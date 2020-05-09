#ifndef ENGINE_TEXTUREDMODEL_H
#define ENGINE_TEXTUREDMODEL_H

#include "RawModel.h"
#include "Texture.h"

class TexturedModel
{
private:
    RawModel rawModel;
    Texture texture;

public:
    TexturedModel(const RawModel &rawModel, const Texture &texture);

    const RawModel &getRawModel() const;

    const Texture& getModelTexture() const;
};


#endif //ENGINE_TEXTUREDMODEL_H
