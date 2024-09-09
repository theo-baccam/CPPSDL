#pragma once

#include "keys.hpp"
#include "Grid.hpp"


class View {
    public:
        View();
        ~View();

        virtual void initializeWindow() = 0;
        virtual bool isWindowOpen() = 0;
        virtual enum keys getPressedKey() = 0;
        virtual void draw(Grid grid) = 0;
        virtual bool isCloseWindowPressed() = 0;
        virtual void closeWindow() = 0;
};