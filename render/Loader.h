#ifndef ENGINE_LOADER_H
#define ENGINE_LOADER_H

#include "RawModel.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class Loader {
private:
    std::vector<GLuint> vaos;
    std::vector<GLuint> vbos;

    int createVao();
    void storeDataToVao(int attributeNumber, const std::vector<float>& data);
    static void unbindVao();
public:
    RawModel loadToVao(const std::vector<float>& positions);
    void clean();
};

#endif //ENGINE_LOADER_H
