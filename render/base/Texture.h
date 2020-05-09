//
// Created by Paul D'Pong on 2019-07-25.
//

#ifndef ENGINE_TEXTURE_H
#define ENGINE_TEXTURE_H

#include "Material.h"

class Texture {
private:
    int textureId;
    Material material;

public:
    Texture(int id, Material material);
    const int& getId() const;

    const Material &getMaterial() const;
};


#endif //ENGINE_TEXTURE_H
