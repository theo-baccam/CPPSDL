#include <vector>

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

void Grid::initializeGrid() {}
void Grid::moveTiles(enum direction moveDirection) {}