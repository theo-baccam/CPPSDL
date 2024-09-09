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

bool is_full(Grid grid)
{
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
            if (grid[x][y] == 0)
                return false;
    return true;
}

void flip_vertically(Grid& grid)
{
    for (int x = 0; x < 4; ++x) {
        std::swap(grid[x][0], grid[x][3]);
        std::swap(grid[x][1], grid[x][2]);
    }
}

void flip_diagonally(Grid& grid)
{
    std::swap(grid[1][0], grid[0][1]);
    std::swap(grid[2][0], grid[0][2]);
    std::swap(grid[3][0], grid[0][3]);
    std::swap(grid[2][1], grid[1][2]);
    std::swap(grid[3][1], grid[1][3]);
    std::swap(grid[3][2], grid[2][3]);
}

void squash_column(std::array<int, 4>& col)
{
    for (int dest = 3; dest >= 0; --dest) {
        int src = dest - 1;
        while (src >= 0 && col[src] == 0)
            --src;
        if (src < 0)
            break;
        if (col[dest] == col[src]) {
            col[dest] = col[dest] * 2;
            col[src] = 0;
        }
        if (col[dest] == 0) {
            std::swap(col[dest], col[src]);
            ++dest;
        }
    }
}
