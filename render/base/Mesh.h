#ifndef ENGINE_MESH_H
#define ENGINE_MESH_H

#include <string>
#include <vector>
#include "../../includes/glm/glm.hpp"
#include "Shader.h"

using namespace glm;

struct Vertex {
    vec3 positionVec;
    vec3 normalVec;
    vec2 textureCoords;
} typedef Vertex;

enum TextureType {
    TEXTURE_DIFFUSE,
    TEXTURE_SPECULAR
};

struct Texture {
    unsigned int id;
    TextureType type;
} typedef Texture;

class Mesh {
public:
    Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices,
         const std::vector<Texture> &textures);
    const std::vector<Vertex> &getVertices() const;
    const std::vector<unsigned int> &getIndices() const;
    const std::vector<Texture> &getTextures() const;

    void draw(Shader shader);
private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    unsigned int idVAO, idVBO, idEBO;
    void setupMesh();
};


#endif //ENGINE_MESH_H
