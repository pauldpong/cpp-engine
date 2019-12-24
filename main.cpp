#include <iostream>
using namespace std;

#include "render/DisplayManager.h"
#include "render/Loader.h"
#include "render/Renderer.h"
#include "render/StaticShader.h"
#include "render/Texture.h"
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

    StaticShader shader;
    shader.getUniformLocations();
    RawModel model = loader.loadToVao(triangle, textureCoords,indices);
    Texture texture = Texture(loader.loadTexture("../assets/container.jpg"));
    TexturedModel texturedModel = TexturedModel(model, texture);

    Renderer renderer = Renderer(shader);

    Entity entity = Entity(texturedModel, glm::vec3(0, 0, -1), 0, 0, 0, 1);

    while (!display.closeRequested()) {
        entity.increasePosition(0, 0, -0.1f);

        renderer.prepare();

        shader.start();
        renderer.render(entity, shader);
        shader.stop();

        glfwPollEvents();
        display.refresh();
    }

    shader.clean();
    loader.clean();
    display.close();
    return 0;
}