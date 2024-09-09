#define MIN_INDEX 0
#define MAX_INDEX 3
#define GRID_SIZE 4


#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>

#include "keys.hpp"
#include "Grid.hpp"

Grid::Grid() {
    this->grid = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
}
Grid::~Grid() {}

void Grid::initializeGrid() {
    for (int y = MIN_INDEX; y < GRID_SIZE; y++) {
        for (int x = MIN_INDEX; x < GRID_SIZE; x++) {
            if (this->grid[y][x] == 0) {
                continue;
            }

            this->grid[y][x] = 0;
        }
    }

    spawnNewTile();
    spawnNewTile();
}

void Grid::spawnNewTile() {
    srand(time(0));

    int randomX;
    int randomY;

    do {
        randomY = rand() % GRID_SIZE;
        randomX = rand() % GRID_SIZE;
    } while (this->grid[randomY][randomX] != 0);

    int randomValue = (rand() % 2 + 1) * 2;

    this->grid[randomY][randomX] = randomValue;
}

struct moveConfiguration Grid::getLeftMoveConfiguration(int &y, int &x) {
    struct moveConfiguration cfg = {
        MIN_INDEX,

        &y,
        [&y]() {return y < GRID_SIZE;},
        [&y]() {y++;},

        &x,
        [&x]() {return x < GRID_SIZE;},
        [&x]() {x++;},

        0,
        -1
    };

    return cfg;
}

struct moveConfiguration Grid::getRightMoveConfiguration(int &y, int &x) {
    struct moveConfiguration cfg = {
        MAX_INDEX,

        &y,
        [&y]() {return y >= MIN_INDEX;},
        [&y]() {y--;},

        &x,
        [&x]() {return x >= MIN_INDEX;},
        [&x]() {x--;},

        0,
        1
    };

    return cfg;
}

struct moveConfiguration Grid::getDownMoveConfiguration(int &y, int &x) {
    struct moveConfiguration cfg = {
        MIN_INDEX,

        &x,
        [&x]() {return x < GRID_SIZE;},
        [&x]() {x++;},

        &y,
        [&y]() {return y < GRID_SIZE;},
        [&y]() {y++;},

        1,
        0
    };

    return cfg;
}

struct moveConfiguration Grid::getUpMoveConfiguration(int &y, int &x) {
    struct moveConfiguration cfg = {
        MAX_INDEX,

        &x,
        [&x]() {return x >= MIN_INDEX;},
        [&x]() {x--;},

        &y,
        [&y]() {return y >= MIN_INDEX;},
        [&y]() {y--;},

        -1,
        0
    };

    return cfg;
}

void Grid::moveTiles(enum keys moveDirection) {
    int y;
    int x;

    struct moveConfiguration cfg;

    std::vector<std::vector<bool>> fusedSquares = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    switch (moveDirection) {
        case LEFT:
            cfg = getLeftMoveConfiguration(y, x);
            break;
        case RIGHT:
            cfg = getRightMoveConfiguration(y, x);
            break;
        case DOWN:
            cfg = getDownMoveConfiguration(y, x);
            break;
        case UP:
            cfg = getUpMoveConfiguration(y, x);
            break;
    }

    bool change;
    do {
        change = false;

        *(cfg.loop1) = cfg.loopStart;
        for (;cfg.loop1Condition(); cfg.loop1Increment()) {
            *(cfg.loop2) = cfg.loopStart;
            for (;cfg.loop2Condition(); cfg.loop2Increment()) {
                // blank square
                if (grid[y][x] == 0) {
                    continue;
                }

                // wall collision
                if (y + cfg.yAhead < MIN_INDEX   
                    || y + cfg.yAhead > MAX_INDEX
                    || x + cfg.xAhead < MIN_INDEX
                    || x + cfg.xAhead > MAX_INDEX
                ) {
                    continue;
                }

                // skip if fused
                if (fusedSquares[y][x]) {
                    continue;
                }

                // if colliding into fused square
                if (
                    fusedSquares[y + cfg.yAhead][x + cfg.xAhead]
                ) {
                    continue;
                }

                // No fusion collision
                if (
                    grid[y + cfg.yAhead][x + cfg.xAhead] != 0
                    && grid[y + cfg.yAhead][x + cfg.xAhead] != grid[y][x]
                ) {
                    continue;
                }

                change = true;

                // fusion
                if (grid[y + cfg.yAhead][x + cfg.xAhead] == grid[y][x]) {
                    grid[y + cfg.yAhead][x + cfg.xAhead] *= 2;
                    grid[y][x] = 0;
                    fusedSquares[y + cfg.yAhead][x + cfg.xAhead] = 1;
                    continue;
                }

                grid[y + cfg.yAhead][x + cfg.xAhead] = grid[y][x];
                grid[y][x] = 0;
            }
        }
    } while (change);
}