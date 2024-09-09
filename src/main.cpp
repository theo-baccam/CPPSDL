#include "Controller.hpp"
#include "View.hpp"
#include "TerminalView.hpp"


int main() {
    TerminalView view;
    Controller controller(&view);
    controller.run();

    return 0;
}