#include "TexturedModel.h"

const Texture& TexturedModel::getModelTexture() const{
    return texture;
}

TexturedModel::TexturedModel(const RawModel &rawModel, const Texture &texture)
    : rawModel(rawModel),texture(texture) {}

const RawModel &TexturedModel::getRawModel() const {
    return rawModel;
}
