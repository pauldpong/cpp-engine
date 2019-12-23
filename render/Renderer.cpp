#include "Renderer.h"

void Renderer::prepare() {
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(TexturedModel model) {
    RawModel rawModel = model.getRawModel();

    glBindVertexArray(rawModel.getVaoId());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model.getModelTexture().getId());

    glDrawElements(GL_TRIANGLES, rawModel.getVertexCount(), GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}
