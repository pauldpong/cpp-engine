#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices,
           const std::vector<Texture> &textures) : vertices(vertices), indices(indices), textures(textures) {
    setupMesh();
}

const std::vector<Vertex> &Mesh::getVertices() const {
    return vertices;
}

const std::vector<unsigned int> &Mesh::getIndices() const {
    return indices;
}

const std::vector<Texture> &Mesh::getTextures() const {
    return textures;
}

void Mesh::setupMesh() {
    glGenVertexArrays(1, &idVAO);
    glGenBuffers(1, &idVBO);
    glGenBuffers(1, &idEBO);

    glBindVertexArray(idVAO);

    // add Vertex data to VBO
    glBindBuffer(GL_ARRAY_BUFFER, idVBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_COPY);

    // add index data to EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normalVec));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoords));

    glBindVertexArray(0);
}

void Mesh::draw(Shader shader) {
    unsigned int diffuseNum = 0;
    unsigned int specularNum = 0;

    for (unsigned int textureIndex = 0; textureIndex < textures.size(); textureIndex++) {
        glActiveTexture(GL_TEXTURE0 + textureIndex);

        std::string number;
        TextureType textureType = textures[textureIndex].type;

        switch (textureType) {
            case TEXTURE_DIFFUSE:
                diffuseNum++;
                break;
            case TEXTURE_SPECULAR:
                specularNum++;
                break;
            default:
                break;
        }
    }
    glActiveTexture(GL_TEXTURE0);

    // draw mesh
    glBindVertexArray(idVAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}
