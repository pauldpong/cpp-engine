#include "MasterRenderer.h"

void MasterRenderer::render(Light light, Camera camera) {
    prepare();
    shader.start();

    shader.loadLight(light);
    shader.loadViewMatrix(camera.getViewMatrix());
    renderer.render(entities);
    shader.stop();

    terrainShader.start();
    terrainShader.loadLight(light);
    terrainShader.loadViewMatrix(camera.getViewMatrix());
    terrainRenderer.render(terrainGrids);
    terrainShader.stop();

    terrainGrids.clear();
    entities.clear();
}

void MasterRenderer::processEntity(Entity entity) {
    int textureId = entity.getModel().getModelTexture().getId();

    auto it = entities.find(textureId);

    if (it == entities.end()) {
        std::vector<Entity> batch = {entity};

        entities.emplace(textureId, batch);
    } else {
        it->second.push_back(entity);
    }
}

void MasterRenderer::processTerrainGrid(TerrainGrid terrainGrid) {
    terrainGrids.push_back(terrainGrid);
}

void MasterRenderer::clean() {
    terrainShader.clean();
    shader.clean();
}

MasterRenderer::MasterRenderer() :
    renderer(shader, perspective(Maths::toRadian(FOV), (float) DisplayManager::getWinWidth() / (float) DisplayManager::getWinHeight(),NEAR_PLANE,FAR_PLANE)),
    terrainRenderer(terrainShader, perspective(Maths::toRadian(FOV), (float) DisplayManager::getWinWidth() / (float) DisplayManager::getWinHeight(),NEAR_PLANE,FAR_PLANE))
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void MasterRenderer::prepare() {
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
