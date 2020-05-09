#include <iostream>
using namespace std;

#include "render/DisplayManager.h"
#include "render/Loader.h"
#include "render/MasterRenderer.h"
#include "render/base/StaticShader.h"
#include "render/base/Texture.h"
#include "render/base/TexturedModel.h"
#include "render/entities/Camera.h"

#include "render/base/ObjLoader.h"

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

int main() {
    DisplayManager display;

    DisplayCreationStatus displayCreationStatus = display.create();
    if (displayCreationStatus == INIT_ERROR) { return -1; }

    Loader loader;

    MasterRenderer renderer;

    RawModel model = ObjLoader::loadObjModel("../assets/dragon.obj", loader);
    Material material = Material(1, 10);
    Material terrainMat = Material();
    Texture texture = Texture(loader.loadTexture("../assets/wood.jpg"), material);
    Texture grass = Texture(loader.loadTexture("../assets/grass.jpg"), terrainMat);
    TexturedModel texturedModel = TexturedModel(model, texture);

    Entity entity = Entity(texturedModel, glm::vec3(0, 0, 0), 0, 0, 0, 1);

    TerrainGrid grid0 = TerrainGrid(0, 0, loader, grass);
    TerrainGrid grid1 = TerrainGrid(-1, -1, loader, grass);
    TerrainGrid grid2 = TerrainGrid(-1, 0, loader, grass);
    TerrainGrid grid3 = TerrainGrid(0, -1, loader, grass);

    Camera camera;
    Light light(vec3(0, 0, -20), vec3(1, 1, 1));

    while (!display.closeRequested()) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        renderer.processEntity(entity);
        renderer.processTerrainGrid(grid0);
        renderer.processTerrainGrid(grid1);
        renderer.processTerrainGrid(grid2);
        renderer.processTerrainGrid(grid3);

        renderer.render(light, camera);
        display.refresh();
        glfwPollEvents();
    }

    renderer.clean();
    loader.clean();
    display.close();
    return 0;
}