#include "TexturedModel.h"

RawModel TexturedModel::getRawModel()
{
    return rawModel;
}

Texture TexturedModel::getModelTexture()
{
    return texture;
}

TexturedModel::TexturedModel(const RawModel &rawModel, const Texture &texture)
    : rawModel(rawModel),texture(texture) {}
