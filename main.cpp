#include <iostream>

#include "render/DisplayManager.h"
#include "render/Loader.h"
#include "render/Renderer.h"
#include "render/StaticShader.h"

int main() {
    std::vector<float> triangle = {
            -0.5, 0.5, 0,
            -0.5, -0.5, 0,
            0.5, -0.5, 0,
            0.5, -0.5, 0,
            0.5, 0.5, 0,
            -0.5, 0.5, 0
    };

    DisplayManager display;

    DisplayCreationStatus displayCreationStatus = display.create();
    if (displayCreationStatus == INIT_ERROR) { return -1; }

    Loader loader;
    Renderer renderer;
    StaticShader shader;
    RawModel model = loader.loadToVao(triangle);

    while (!display.closeRequested()) {
        glfwPollEvents();
        renderer.prepare();

        shader.start();
        renderer.render(model);
        shader.stop();

        display.refresh();
    }

    shader.clean();
    loader.clean();
    display.close();
    return 0;
}