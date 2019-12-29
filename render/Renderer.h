#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include "../includes.h"
#include "base/TexturedModel.h"
#include "entities/Entity.h"
#include "base/StaticShader.h"
#include "Maths.h"
#include "entities/Camera.h"

class Renderer {
public:
    void render(Entity entity, StaticShader shader, Camera camera);
private:
    static constexpr float FOV = 70;
    static constexpr float NEAR_PLANE = 0.1f;
    static constexpr float FAR_PLANE = 1000;
};


#endif //ENGINE_RENDERER_H
