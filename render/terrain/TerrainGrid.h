//
// Created by Paul D'Pong on 2020-05-08.
//

#ifndef ENGINE_TERRAINGRID_H
#define ENGINE_TERRAINGRID_H


#include "../base/RawModel.h"
#include "../base/Texture.h"
#include "../Loader.h"

class TerrainGrid {
private:
    const float SIZE = 800;
    const int VERTEX_COUNT = 128;

    float gridX;
    float gridZ;
    RawModel gridModel;
    Texture texture;

public:
    TerrainGrid(int gridX, int gridZ, Loader loader, Texture texture);
    RawModel generateTerrain(Loader loader);

    float getGridX() const;

    float getGridZ() const;

    const RawModel &getGridModel() const;

    const Texture &getTexture() const;

};


#endif //ENGINE_TERRAINGRID_H
