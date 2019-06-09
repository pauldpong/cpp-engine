#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include "RawModel.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Renderer {
public:
    void prepare();
    void render(RawModel model);
};


#endif //ENGINE_RENDERER_H
