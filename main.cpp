#include <iostream>

#include "DisplayManager.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    DisplayManager display;

    DisplayCreationStatus displayCreationStatus = display.create();
    if (displayCreationStatus == INIT_ERROR) { return -1; }

    while (!display.closeRequested()) {
        display.refresh();
        glfwPollEvents();
    }

    display.close();
    return 0;
}