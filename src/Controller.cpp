#include "keys.hpp"
#include "Controller.hpp"
#include "Grid.hpp"
#include "View.hpp"


Controller::Controller(View* view) {
    this->view = view;
}
Controller::~Controller() {}

void Controller::run() {
    view->initializeWindow();
    grid.initializeGrid();

    while (view->isWindowOpen()) {
        enum keys pressedKey = view->getPressedKey();
        if (pressedKey != NONE) {
            if (grid.moveTiles(pressedKey)) {
                grid.spawnNewTile();
            }
        }
        view->draw(grid);
        if (view->isCloseWindowPressed()) {
            view->closeWindow();
        }
    }
}