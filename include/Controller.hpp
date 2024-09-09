#pragma once

#include "keys.hpp"
#include "Grid.hpp"
#include "View.hpp"


class Controller {
    public:
        Controller(View* view);
        ~Controller();

        Grid grid;
        View* view;
        void run();
};