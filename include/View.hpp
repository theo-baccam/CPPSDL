#pragma once

#include "keys.hpp"
#include "Grid.hpp"


class View {
    public:
        View();
        ~View();

        virtual void initializeWindow();
        virtual bool isWindowOpen();
        virtual enum keys getPressedKey();
        virtual void draw(Grid grid);
        virtual bool isCloseWindowPressed();
        virtual void closeWindow();
};