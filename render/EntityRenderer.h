#ifndef ENGINE_ENTITYRENDERER_H
#define ENGINE_ENTITYRENDERER_H

#include "../includes.h"
#include "base/TexturedModel.h"
#include "entities/Entity.h"
#include "base/StaticShader.h"
#include "Maths.h"
#include "entities/Camera.h"
#include <unordered_map>

class EntityRenderer {
public:
    EntityRenderer(StaticShader shader, mat4 projectionMatrix);

    void render(std::unordered_map<int, std::vector<Entity>> entities);
private:
    StaticShader shader;

    void prepareTexturedModel(TexturedModel model);
    void prepareInstance(Entity entity);
    void unbindTexturedModel();
};


#endif //ENGINE_ENTITYRENDERER_H
