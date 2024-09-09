#pragma once

#include "keys.hpp"
#include "View.hpp"
#include "Grid.hpp"


class TerminalView : public View {
    public:
        TerminalView();
        ~TerminalView();

        void initializeWindow() override;
        bool isWindowOpen() override;
        enum keys getPressedKey() override;
        void draw(Grid grid) override;
        bool isCloseWindowPressed() override;
        void closeWindow() override;
};