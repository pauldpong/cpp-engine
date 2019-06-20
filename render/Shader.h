#ifndef ENGINE_SHADER_H
#define ENGINE_SHADER_H

#include "../includes.h"

class Shader {
private:
    int programId, vertexShaderId, fragmentShaderId;
    char errorBuffer[512] = "";
    int loadShaderFile(const std::string& filePath, GLenum shaderType);
public:
    Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
    void start();
    void stop();
    void clean();
};


#endif //ENGINE_SHADER_H
