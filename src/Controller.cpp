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

    while (view->isWindowOpen()) {
        enum keys pressedKey = view->getPressedKey();
        if (pressedKey != NONE) {
            grid.moveTiles(pressedKey);
        }
        view->draw(grid);
        if (view->isCloseWindowPressed()) {
            view->closeWindow();
        }
    }
}