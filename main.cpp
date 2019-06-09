#include <iostream>

#include "render/DisplayManager.h"
#include "render/Loader.h"
#include "render/Renderer.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<float> triangle = {
            -0.5, 0.5, 0,
            -0.5, -0.5, 0,
            0.5, -0.5, 0,
            0.5, -0.5, 0,
            0.5, 0.5, 0,
            -0.5, 0.5, 0
    };

    DisplayManager display;
    Loader loader;
    Renderer renderer;

    DisplayCreationStatus displayCreationStatus = display.create();
    if (displayCreationStatus == INIT_ERROR) { return -1; }

    RawModel model = loader.loadToVao(triangle);

    while (!display.closeRequested()) {
        renderer.prepare();

        renderer.render(model);

        display.refresh();
        glfwPollEvents();
    }

    loader.clean();
    display.close();
    return 0;
}