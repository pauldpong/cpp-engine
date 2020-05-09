#include "TerrainGrid.h"

TerrainGrid::TerrainGrid(int gridX, int gridZ, Loader loader, Texture texture) : gridX(gridX * SIZE), gridZ(gridZ * SIZE), texture(texture), gridModel(generateTerrain(loader)) {}

float TerrainGrid::getGridX() const {
    return gridX;
}

float TerrainGrid::getGridZ() const {
    return gridZ;
}

const RawModel &TerrainGrid::getGridModel() const {
    return gridModel;
}

const Texture &TerrainGrid::getTexture() const {
    return texture;
}

RawModel TerrainGrid::generateTerrain(Loader loader) {
    int count = VERTEX_COUNT * VERTEX_COUNT;
    std::vector<float> vertices(count * 3);
    std::vector<float> normals(count * 3);
    std::vector<float> textureCoords(count * 2);
    std::vector<int> indices(6 * (VERTEX_COUNT - 1) * (VERTEX_COUNT - 1));

    int vertexIndex = 0;
    for (int z = 0; z < VERTEX_COUNT; z++) {
        for (int x = 0; x < VERTEX_COUNT; x++, vertexIndex++) {
            vertices[vertexIndex * 3] = (float)x / ((float)(VERTEX_COUNT - 1)) * SIZE;
            vertices[vertexIndex * 3 + 1] = 0;
            vertices[vertexIndex * 3 + 2] = (float)z / ((float)(VERTEX_COUNT - 1)) * SIZE;

            normals[vertexIndex * 3] = 0;     //x
            normals[vertexIndex * 3 + 1] = 1; //y
            normals[vertexIndex * 3 + 2] = 0; //z

            textureCoords[vertexIndex * 2] = (float)x / (float)(VERTEX_COUNT - 1);
            textureCoords[vertexIndex * 2 + 1] = (float)z / (float)(VERTEX_COUNT - 1);;
        }
    }

    int gridIndex = 0;
    for (int z = 0; z < VERTEX_COUNT - 1; z++) {
        for (int x = 0; x < VERTEX_COUNT - 1; x++) {
            int topLeftIndex = (z * VERTEX_COUNT) + x;
            int topRightIndex = topLeftIndex + 1;
            int bottomLeftIndex = ((z + 1) * VERTEX_COUNT) + x;
            int bottomRightIndex = bottomLeftIndex + 1;

            indices[gridIndex++] = topLeftIndex;
            indices[gridIndex++] = bottomLeftIndex;
            indices[gridIndex++] = topRightIndex;
            indices[gridIndex++] = topRightIndex;
            indices[gridIndex++] = bottomLeftIndex;
            indices[gridIndex++] = bottomRightIndex;
        }
    }

    return loader.loadToVao(vertices, textureCoords, normals, indices);
}
