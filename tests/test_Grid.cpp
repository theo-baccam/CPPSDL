#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "Grid.hpp"


TEST_CASE("Checking if the grid is initialized correctly") {
    Grid g;
    g.initializeGrid();

    int emptySquareCount = 0;
    int gridSum = 0;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (g.grid[y][x] == 0) {
                emptySquareCount += 1;
                continue;
            }

            gridSum += g.grid[y][x];
        }
    }

    CHECK(emptySquareCount == 14);
    bool gridSumCorrect = (gridSum == 4 || gridSum == 6 || gridSum == 8);
    INFO("The sum of squares on the grid is ", gridSum);
    CHECK(gridSumCorrect);
}