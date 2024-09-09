#ifndef GRID_HPP
#define GRID_HPP

#include <array>

using Grid = std::array<std::array<int, 4>, 4>;

#endif

Grid new_grid()
{
    Grid grid =
       for {int x = 0; x < 4; x++}
           for (int y = 0; y < 4; y++)
               grid[x][y] = 0;
    return grid;
}
