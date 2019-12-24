#include "Renderer.h"
#include "DisplayManager.h"

Renderer::Renderer(StaticShader shader) {
    createProjectionMatrix();
    shader.start();
    shader.loadProjectionMatrix(projectionMatrix);
    shader.stop();
}

void Renderer::createProjectionMatrix() {
    float aspectRatio = (float) DisplayManager::getWinWidth() / (float) DisplayManager::getWinHeight();
    float yScale = (float) ((1.0f / tan(Maths::toRadian(FOV / 2.0f)))) * aspectRatio;
    float xScale = yScale / aspectRatio;
    float frustumLength = FAR_PLANE - NEAR_PLANE;

    projectionMatrix = glm::mat4(0);
    projectionMatrix[0][0] = xScale;
    projectionMatrix[1][1] = yScale;
    projectionMatrix[2][2] = -((FAR_PLANE + NEAR_PLANE) / frustumLength);
    projectionMatrix[2][3] = -1;
    projectionMatrix[3][2] = -((2 * NEAR_PLANE * FAR_PLANE) / frustumLength);
}

void Renderer::prepare()
{
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(Entity entity, StaticShader shader) {
    TexturedModel model = entity.getModel();

    RawModel rawModel = model.getRawModel();

    glBindVertexArray(rawModel.getVaoId());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glm::mat4 transformMatrix =
            Maths::createTransformationMatrix(
                    entity.getPosition(),
                    entity.getRx(),
                    entity.getRy(),
                    entity.getRz(),
                    entity.getScale()
            );
    shader.loadTransformationMatrix(transformMatrix);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model.getModelTexture().getId());

    glDrawElements(GL_TRIANGLES, rawModel.getVertexCount(), GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}
