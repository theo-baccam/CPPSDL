#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "Grid.hpp"

#include <iostream>


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

TEST_CASE("Checking if tile movement works") {
    Grid g;

    SUBCASE("Moving one square") {
        g.grid[0][3] = 2;

        REQUIRE(g.grid[0][3] == 2);

        g.moveTiles(LEFT);
        CHECK(g.grid[0][0] == 2);

        g.moveTiles(DOWN);
        CHECK(g.grid[3][0] == 2);

        g.moveTiles(RIGHT);
        CHECK(g.grid[3][3] == 2);

        g.moveTiles(UP);
        CHECK(g.grid[0][3] == 2);
    }

    SUBCASE("Uncompatible square collision") {
        g.grid[0][3] = 2;
        g.grid[0][0] = 4;

        REQUIRE(g.grid[0][0] == 4);
        REQUIRE(g.grid[0][3] == 2);

        g.moveTiles(LEFT);
        CHECK(g.grid[0][0] == 4);
        CHECK(g.grid[0][1] == 2);
        CHECK(g.grid[0][3] == 0);
    }

    SUBCASE("Square fusion") {
        g.grid[0][0] = 4;
        g.grid[0][1] = 2;
        g.grid[0][3] = 2;

        REQUIRE(g.grid[0][0] == 4);
        REQUIRE(g.grid[0][1] == 2);
        REQUIRE(g.grid[0][3] == 2);

        g.moveTiles(LEFT);
        CHECK(g.grid[0][0] == 4);
        CHECK(g.grid[0][1] == 4);
        CHECK(g.grid[0][3] == 0);
    }
}