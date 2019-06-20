#ifndef ENGINE_LOADER_H
#define ENGINE_LOADER_H

#include "../includes.h"
#include "RawModel.h"

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
