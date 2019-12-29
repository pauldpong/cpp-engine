#include "Renderer.h"
#include "DisplayManager.h"

void Renderer::render(Entity entity, StaticShader shader, Camera camera) {
    TexturedModel model = entity.getModel();

    RawModel rawModel = model.getRawModel();

    glBindVertexArray(rawModel.getVaoId());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    mat4 transformMatrix = Maths::createTransformationMatrix(
            entity.getPosition(),
            entity.getRx(),
            entity.getRy(),
            entity.getRz(),
            entity.getScale()
    );

    mat4 viewMatrix = camera.getViewMatrix();

    mat4 projectionMatrix = perspective(
            Maths::toRadian(FOV),
            (float) DisplayManager::getWinWidth() / (float) DisplayManager::getWinHeight(),
            NEAR_PLANE,
            FAR_PLANE
    );

    mat4 mvp = projectionMatrix * viewMatrix * transformMatrix;

    shader.loadMVP(mvp);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model.getModelTexture().getId());

    glDrawElements(GL_TRIANGLES, rawModel.getVertexCount(), GL_UNSIGNED_INT, nullptr);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}
