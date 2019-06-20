#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include "../includes.h"
#include "RawModel.h"

class Renderer {
public:
    void prepare();
    void render(RawModel model);
};


#endif //ENGINE_RENDERER_H
