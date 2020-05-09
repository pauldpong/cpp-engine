#include "EntityRenderer.h"
#include "DisplayManager.h"

void EntityRenderer::prepareTexturedModel(TexturedModel model) {
    glBindVertexArray(model.getRawModel().getVaoId());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    shader.loadMaterial(model.getModelTexture().getMaterial());

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model.getModelTexture().getId());
}

void EntityRenderer::prepareInstance(Entity entity) {
    mat4 transformMatrix = Maths::createTransformationMatrix(
            entity.getPosition(),
            entity.getRx(),
            entity.getRy(),
            entity.getRz(),
            entity.getScale()
    );

    shader.loadTransformationMatrix(transformMatrix);
}

void EntityRenderer::unbindTexturedModel() {
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}

void EntityRenderer::render(std::unordered_map<int, std::vector<Entity>> entities) {
    for (const auto& it : entities) {
        prepareTexturedModel(it.second[0].getModel());
        std::vector<Entity> batch = it.second;

        for (const Entity& entity : batch) {
            prepareInstance(entity);
            glDrawElements(GL_TRIANGLES, entity.getModel().getRawModel().getVertexCount(), GL_UNSIGNED_INT, nullptr);
        }
        unbindTexturedModel();
    }
}

EntityRenderer::EntityRenderer(StaticShader shader, mat4 projectionMatrix) {
    shader.start();
    shader.loadProjectionMatrix(projectionMatrix);
    shader.stop();
}
