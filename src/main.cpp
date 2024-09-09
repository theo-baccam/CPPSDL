#include "Controller.hpp"
#include "View.hpp"


int main() {
    View view;
    Controller controller(&view);
    controller.run();

    return 0;
}