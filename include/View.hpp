#pragma once

#include "keys.hpp"


class View {
    View();
    ~View();

    virtual void initializeWindow();
    virtual bool isWindowOpen();
    virtual enum keys getPressedKey();
    virtual void draw();
    virtual void closeWindow();
};