#include <iostream>
#include <cstring>

#include "keys.hpp"
#include "View.hpp"
#include "TerminalView.hpp"
#include "Grid.hpp"


bool start = true;


TerminalView::TerminalView() {}
TerminalView::~TerminalView() {}


void TerminalView::initializeWindow() {}
bool TerminalView::isWindowOpen() {return true;}
enum keys TerminalView::getPressedKey() {
    if (start) {
        return NONE;
    }

    std::string prompt;
    std::cin >> prompt;
    if (prompt == "h") {
        return LEFT;
    } else if (prompt == "j") {
        return DOWN;
    } else if (prompt == "k") {
        return UP;
    } else if (prompt == "l") {
        return RIGHT;
    }

    return NONE;
}
void TerminalView::draw(Grid grid) {
    if (start) {start = false;};
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            std::cout << grid.grid[y][x] << " ";
        }
        std::cout << '\n';
    }
    std::cout << "h) LEFT    j) DOWN    k) UP    l) RIGHT\n";
}
bool TerminalView::isCloseWindowPressed() {return false;}
void TerminalView::closeWindow() {}