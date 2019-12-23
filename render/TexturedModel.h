//
// Created by Paul D'Pong on 2019-07-25.
//

#ifndef ENGINE_TEXTUREDMODEL_H
#define ENGINE_TEXTUREDMODEL_H

#include "RawModel.h"
#include "ModelTexture.h"

class TexturedModel {
private:
    RawModel rawModel;
    ModelTexture modelTexture;

public:
    TexturedModel(const RawModel &rawModel, const ModelTexture &modelTexture);

    RawModel getRawModel();
    ModelTexture getModelTexture();
};


#endif //ENGINE_TEXTUREDMODEL_H
