#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include "../includes.h"
#include "TexturedModel.h"
#include "entities/Entity.h"
#include "StaticShader.h"
#include "Maths.h"

class Renderer {
public:
    void render(Entity entity, StaticShader shader);
private:
    static constexpr float FOV = 70;
    static constexpr float NEAR_PLANE = 0.1f;
    static constexpr float FAR_PLANE = 1000;
};


#endif //ENGINE_RENDERER_H
