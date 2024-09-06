#define MIN_INDEX 0
#define MAX_INDEX 3
#define GRID_SIZE 4


#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>

#include "Grid.hpp"

#include <iostream>


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

void Grid::moveTiles(enum direction moveDirection) {
    int y;
    int x;
    int loopStart;
    int* loop1;
    int* loop2;

    std::function<bool()> loop1Condition;
    std::function<bool()> loop2Condition;
    std::function<void()> loop1Increment;
    std::function<void()> loop2Increment;
    int yAhead;
    int xAhead;

    switch (moveDirection) {
        case LEFT:
            loop1Condition = [&]() {return y < GRID_SIZE;};
            loop2Condition = [&]() {return x < GRID_SIZE;};
            loop1Increment = [&]() {y++;};
            loop2Increment = [&]() {x++;};
            yAhead = 0;
            xAhead = -1;
            loop1 = &y;
            loop2 = &x;
            loopStart = MIN_INDEX;
            break;
        case RIGHT:
            loop1Condition = [&]() {return y >= MIN_INDEX;};
            loop2Condition = [&]() {return x >= MIN_INDEX;};
            loop1Increment = [&]() {y--;};
            loop2Increment = [&]() {x--;};
            yAhead = 0;
            xAhead = 1;
            loop1 = &y;
            loop2 = &x;
            loopStart = MAX_INDEX;
            break;
        case DOWN:
            loop1Condition = [&]() {return x < GRID_SIZE;};
            loop2Condition = [&]() {return y < GRID_SIZE;};
            loop1Increment = [&]() {x++;};
            loop2Increment = [&]() {y++;};
            yAhead = 1;
            xAhead = 0;
            loop1 = &x;
            loop2 = &y;
            loopStart = MIN_INDEX;
            break;
        case UP:
            loop1Condition = [&]() {return x >= MIN_INDEX;};
            loop2Condition = [&]() {return y >= MIN_INDEX;};
            loop1Increment = [&]() {x--;};
            loop2Increment = [&]() {y--;};
            yAhead = -1;
            xAhead = 0;
            loop1 = &x;
            loop2 = &y;
            loopStart = MAX_INDEX;
            break;
    }

    bool change;
    do {
        change = false;

        *(loop1) = loopStart;
        for (;loop1Condition(); loop1Increment()) {
            *(loop2) = loopStart;
            for (;loop2Condition(); loop2Increment()) {
                // blank square
                if (grid[y][x] == 0) {
                    continue;
                }

                // wall collision
                if (y + yAhead < MIN_INDEX   
                    || y + yAhead > MAX_INDEX
                    || x + xAhead < MIN_INDEX
                    || x + xAhead > MAX_INDEX
                ) {
                    continue;
                }

                // No fusion collision
                if (
                    grid[y + yAhead][x + xAhead] != 0
                    && grid[y + yAhead][x + xAhead] != grid[y][x]
                ) {
                    continue;
                }

                change = true;

                // fusion
                if (grid[y + yAhead][x + xAhead] == grid[y][x]) {
                    grid[y + yAhead][x + xAhead] *= 2;
                    grid[y][x] = 0;
                    continue;
                }

                grid[y + yAhead][x + xAhead] = grid[y][x];
                grid[y][x] = 0;
            }
        }
    } while (change);
}