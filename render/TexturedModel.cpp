//
// Created by Paul D'Pong on 2019-07-25.
//

#include "TexturedModel.h"

RawModel TexturedModel::getRawModel() {
    return rawModel;
}

ModelTexture TexturedModel::getModelTexture() {
    return modelTexture;
}

TexturedModel::TexturedModel(const RawModel &rawModel, const ModelTexture &modelTexture) : rawModel(rawModel),
                                                                                           modelTexture(modelTexture) {}
