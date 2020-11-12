#include "Loader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"

int Loader::createVao() {
    GLuint vaoId;
    glGenVertexArrays(1, &vaoId);
    vaoIds.push_back(vaoId);

    return vaoId;
}

void Loader::storeDataToVao(int attributeIndex, int size, const std::vector<float>& data) {
    GLuint vboId;
    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, (data.size() * sizeof(float)), data.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(
            attributeIndex, // index - must match the layout in the shader
            size, // size
            GL_FLOAT, // type
            GL_FALSE, // normalized?
            0, // stride
            nullptr // offset
    );

    vboIds.push_back(vboId);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

int Loader::loadTexture(const std::string& fileName) {
     GLuint textureId;

     glGenTextures(1, &textureId);
     glBindTexture(GL_TEXTURE_2D, textureId);

     int width, height, nrChannels;

     unsigned char *data = stbi_load(fileName.c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);

     if (data) {
         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
         glGenerateMipmap(GL_TEXTURE_2D);
         textureIds.push_back(textureId);
     } else {
         std::cout << "Failed to load image" << std::endl;
     }

     stbi_image_free(data);

     return textureId;
}

void Loader::bindIndicesBuffer(const std::vector<int> &indices) {
    GLuint vboId;
    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int) ,indices.data(), GL_STATIC_DRAW);

    vboIds.push_back(vboId);
}

void Loader::bindVao(const int vaoId) {
    glBindVertexArray(vaoId);
}

void Loader::unbindVao() {
    glBindVertexArray(0);
}

RawModel Loader::loadToVao(const std::vector<float>& positions, const std::vector<float>& texture, const std::vector<float>& normals, const std::vector<int>& indices) {
    int vaoId = createVao();
    bindVao(vaoId);

    storeDataToVao(0, 3, positions);
    storeDataToVao(1, 2, texture);
    storeDataToVao(2, 3, normals);
    bindIndicesBuffer(indices);
    unbindVao();

    return { vaoId, (int) indices.size() };
}

void Loader::clean() {
    glDeleteVertexArrays(vaoIds.size(), vaoIds.data());
    glDeleteBuffers(vboIds.size(), vboIds.data());
    glDeleteTextures(textureIds.size(), textureIds.data());
}
