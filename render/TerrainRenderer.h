//
// Created by Paul D'Pong on 2020-05-09.
//

#ifndef ENGINE_TERRAINRENDERER_H
#define ENGINE_TERRAINRENDERER_H


#include "base/TerrainShader.h"
#include "terrain/TerrainGrid.h"
#include "entities/Entity.h"

class TerrainRenderer {
private:
    TerrainShader shader;

    void prepareTerrainGrid(TerrainGrid terrain);
    void loadModelMatrix(TerrainGrid terrain);
    void unbindTexturedModel();

public:
    TerrainRenderer(TerrainShader shader, mat4 projectionMatrix);
    void render(std::vector<TerrainGrid> terrainGrids);

};


#endif //ENGINE_TERRAINRENDERER_H
