#include <vector>
#include <cstdlib>
#include <ctime>

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
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (this->grid[y][x] == 0) {
                continue;
            }

            this->grid[y][x] = 0;
        }
    }

    srand(time(0));

    for (int i = 0; i < 2; i++) {
        int randomX;
        int randomY;

        do {
            randomY = rand() % 4;
            randomX = rand() % 4;
        } while (this->grid[randomY][randomX] != 0);

        int randomValue = (rand() % 2 + 1) * 2;

        this->grid[randomY][randomX] = randomValue;
    }
}
void Grid::moveTiles(enum direction moveDirection) {}