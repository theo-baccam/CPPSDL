#pragma once

#include <vector>


enum direction {LEFT, RIGHT, UP, DOWN};

class Grid {
    public:
        Grid();
        ~Grid();

        std::vector<std::vector<unsigned int>> grid;

        void initializeGrid();
        void spawnNewTile();
        void moveTiles(enum direction moveDirection);
};