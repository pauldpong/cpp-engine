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

void Loader::bindIndicesBuffer(const std::vector<int> &indices) {
    GLuint vboId;
    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int) ,indices.data(), GL_STATIC_DRAW);

    vbos.push_back(vboId);
}

int Loader::loadTexture(std::string fileName) {
    Texture texture = nullptr;
    return 0;
}

void Loader::unbindVao() {
    glBindVertexArray(0);
}

RawModel Loader::loadToVao(const std::vector<float>& positions, const std::vector<int>& indices) {
    int vaoId = createVao();
    storeDataToVao(0, positions);
    bindIndicesBuffer(indices);
    unbindVao();

    return { vaoId, (int) indices.size() } ;
}

void Loader::clean() {
    glDeleteVertexArrays(vaos.size(), vaos.data());
    glDeleteBuffers(vbos.size(), vbos.data());
}
