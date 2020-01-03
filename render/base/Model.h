#ifndef ENGINE_MODEL_H
#define ENGINE_MODEL_H

#include <string>
#include "Mesh.h"
#include "Shader.h"

class Model {
public:
    Model(char* path);
    void draw(Shader shader);

private:
    std::vector<Mesh> meshes;
    std::string directory;

    void loadModel(std::string path);
};


#endif //ENGINE_MODEL_H
