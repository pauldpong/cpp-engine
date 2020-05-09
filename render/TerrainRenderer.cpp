//
// Created by Paul D'Pong on 2020-05-09.
//

#include "TerrainRenderer.h"
#include "Maths.h"

TerrainRenderer::TerrainRenderer(TerrainShader shader, mat4 projectionMatrix) {
    shader.start();
    shader.loadProjectionMatrix(projectionMatrix);
    shader.stop();
}

void TerrainRenderer::render(std::vector<TerrainGrid> terrainGrids) {
    for (const TerrainGrid& grid : terrainGrids) {
        prepareTerrainGrid(grid);
        loadModelMatrix(grid);

        glDrawElements(GL_TRIANGLES, grid.getGridModel().getVertexCount(), GL_UNSIGNED_INT, nullptr);
    }

    unbindTexturedModel();
}

void TerrainRenderer::prepareTerrainGrid(TerrainGrid terrain) {
    glBindVertexArray(terrain.getGridModel().getVaoId());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    shader.loadMaterial(terrain.getTexture().getMaterial());

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, terrain.getTexture().getId());
}

void TerrainRenderer::loadModelMatrix(TerrainGrid terrain) {
    mat4 transformMatrix = Maths::createTransformationMatrix(vec3(terrain.getGridX(), 0, terrain.getGridZ()), 0, 0, 0, 1);

    shader.loadTransformationMatrix(transformMatrix);
}

void TerrainRenderer::unbindTexturedModel() {
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}
