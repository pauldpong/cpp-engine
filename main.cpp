#include <iostream>
using namespace std;

#include "render/DisplayManager.h"
#include "render/Loader.h"
#include "render/Renderer.h"
#include "render/StaticShader.h"
#include "render/ModelTexture.h"
#include "render/TexturedModel.h"

int main() {
    std::vector<float> triangle = {
            -0.5, 0.5, 0,
            -0.5, -0.5, 0,
            0.5, -0.5, 0,
            0.5, 0.5, 0
    };

    std::vector<int> indices = {
            0, 1, 3,
            3, 1, 2
    };

    std::vector<float> textureCoords = {
            0, 0,
            0, 1,
            1, 1,
            1, 0
    };

    DisplayManager display;

    DisplayCreationStatus displayCreationStatus = display.create();
    if (displayCreationStatus == INIT_ERROR) { return -1; }

    Loader loader;
    Renderer renderer;
    StaticShader shader;
    RawModel model = loader.loadToVao(triangle, textureCoords,indices);
    ModelTexture texture = ModelTexture(loader.loadTexture("../assets/container.jpg"));
    TexturedModel texturedModel = TexturedModel(model, texture);

    while (!display.closeRequested()) {
        glfwPollEvents();
        renderer.prepare();

        shader.start();
        renderer.render(texturedModel);
        shader.stop();

        display.refresh();
    }

    shader.clean();
    loader.clean();
    display.close();
    return 0;
}