#ifndef ENGINE_MASTERRENDERER_H
#define ENGINE_MASTERRENDERER_H


#include "base/StaticShader.h"
#include "EntityRenderer.h"
#include "TerrainRenderer.h"
#include <unordered_map>

class MasterRenderer {
private:
    static constexpr float FOV = 70;
    static constexpr float NEAR_PLANE = 0.1f;
    static constexpr float FAR_PLANE = 1000;

    static constexpr float RED = 0.5f;
    static constexpr float GREEN = 0.5f;
    static constexpr float BLUE = 0.5f;

    StaticShader shader;
    TerrainShader terrainShader;

    TerrainRenderer terrainRenderer;
    EntityRenderer renderer;

    std::unordered_map<int, std::vector<Entity>> entities;
    std::vector<TerrainGrid> terrainGrids;

public:
    MasterRenderer();

    void render(Light light, Camera camera);
    void prepare();
    void processEntity(Entity entity);
    void processTerrainGrid(TerrainGrid terrainGrid);
    void clean();

    static void setCulling(bool enableCulling);
};


#endif //ENGINE_MASTERRENDERER_H
