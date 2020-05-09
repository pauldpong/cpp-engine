//
// Created by Paul D'Pong on 2019-07-25.
//

#include "Texture.h"

Texture::Texture(int id, Material material) : textureId(id), material(material) {}

const int& Texture::getId() const {
    return textureId;
}

const Material &Texture::getMaterial() const {
    return material;
}
