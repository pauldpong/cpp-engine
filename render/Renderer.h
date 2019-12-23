#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include "../includes.h"
#include "TexturedModel.h"

class Renderer {
public:
    void prepare();
    void render(TexturedModel model);
};


#endif //ENGINE_RENDERER_H
