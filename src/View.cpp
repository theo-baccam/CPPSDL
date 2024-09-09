#include "keys.hpp"
#include "View.hpp"


View::View() {}
View::~View() {}

void View::initializeWindow() {}
bool View::isWindowOpen() {return true;}
enum keys View::getPressedKey() {return LEFT;}
void View::draw(Grid grid) {}
bool View::isCloseWindowPressed() {return true;}
void View::closeWindow() {}