#ifndef ENGINE_LOADER_H
#define ENGINE_LOADER_H

#include "../includes.h"
#include "base/RawModel.h"

class Loader {
private:
    std::vector<GLuint> vaoIds;
    std::vector<GLuint> vboIds;
    std::vector<GLuint> textureIds;

    int createVao();
    void storeDataToVao(int attributeNumber, int coordinateSize, const std::vector<float>& data);
    void bindIndicesBuffer(const std::vector<int>& indices);

    static void bindVao(const int vaoId);
    static void unbindVao();
public:
    RawModel loadToVao(const std::vector<float>& positions, const std::vector<float>& texture, const std::vector<float>& normals, const std::vector<int>& indices);
    int loadTexture(const std::string& fileName);
    void clean();
};

#endif //ENGINE_LOADER_H
