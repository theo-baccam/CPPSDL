#pragma once

#include <vector>
#include <functional>

#include "keys.hpp"


struct moveConfiguration {
    int loopStart;

    int* loop1;
    std::function<bool()> loop1Condition;
    std::function<void()> loop1Increment;

    int* loop2;
    std::function<bool()> loop2Condition;
    std::function<void()> loop2Increment;

    int yAhead;
    int xAhead;
};

class Grid {
    public:
        Grid();
        ~Grid();

        std::vector<std::vector<unsigned int>> grid;

        void initializeGrid();
        void spawnNewTile();

        struct moveConfiguration getLeftMoveConfiguration(int &y, int &x);
        struct moveConfiguration getRightMoveConfiguration(int &y, int &x);
        struct moveConfiguration getDownMoveConfiguration(int &y, int &x);
        struct moveConfiguration getUpMoveConfiguration(int &y, int &x);

        void moveTiles(enum keys moveDirection);
};