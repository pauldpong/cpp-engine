#include "Loader.h"

int Loader::createVao() {
    GLuint vaoId;
    glGenVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);

    vaos.push_back(vaoId);

    return vaoId;
}

void Loader::storeDataToVao(int attributeIndex, const std::vector<float>& data) {
    GLuint vboId;
    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, (data.size() * sizeof(float)), data.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(attributeIndex, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    vbos.push_back(vboId);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVao() {
    glBindVertexArray(0);
}

RawModel Loader::loadToVao(const std::vector<float>& positions) {
    int vaoId = createVao();
    storeDataToVao(0, positions);
    unbindVao();

    return { vaoId, (int) positions.size() / 3 } ;
}

void Loader::clean() {
    glDeleteVertexArrays(vaos.size(), vaos.data());
    glDeleteBuffers(vbos.size(), vbos.data());
}
