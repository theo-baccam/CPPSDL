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

void new_number(Grid grid)
{
    while (true) {
        int x = cg::random_int(3);
        int y = cg::random_int(3);
        if (grid[x][y] == 0) {
            grid[x][y] = 2;
            return;
        }
    }
}