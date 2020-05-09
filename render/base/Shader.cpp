#include <sstream>
#include "Shader.h"
#include "../../includes/glm/gtc/type_ptr.hpp"

Shader::Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath) {
    vertexShaderId = loadShaderFile(vertexShaderFilePath, GL_VERTEX_SHADER);
    fragmentShaderId = loadShaderFile(fragmentShaderFilePath, GL_FRAGMENT_SHADER);

    programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);

    int linkSuccessFlag;
    glGetProgramiv(programId, GL_LINK_STATUS, &linkSuccessFlag);
    if (!linkSuccessFlag) {
        glGetProgramInfoLog(programId, 512, nullptr, errorBuffer);
        std::cout << "Unable to link shaders\n" << errorBuffer << std::endl;
    }

    glValidateProgram(programId);
}

void Shader::start() {
    glUseProgram(programId);
}

void Shader::stop() {
    glUseProgram(0);
}

int Shader::getUniformLocation(std::string uniformName) {
    return glGetUniformLocation(programId, uniformName.c_str());
}

void Shader::loadUniformFloat(int location, float value) {
    glUniform1f(location, value);
}

void Shader::loadUniformVector(int location, vec3 vector) {
    glUniform3f(location, vector.x, vector.y, vector.z);
}

void Shader::loadUniformBool(int location, bool value) {
    int numericBoolValue = value ? 1 : 0;
    glUniform1f(location, numericBoolValue);
}

void Shader::loadUniformMatrix(int location, glm::mat4 matrix) {
    glUniformMatrix4fv(location, 1, false, glm::value_ptr(matrix));
}

void Shader::clean() {
    stop();
    glDetachShader(programId, vertexShaderId);
    glDetachShader(programId, fragmentShaderId);
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
    glDeleteProgram(programId);
}

int Shader::loadShaderFile(const std::string& filePath, GLenum shaderType) {
    std::ifstream ifs;
    std::string rawShaderCode;

    ifs.exceptions(std::ifstream::badbit);

    try {
        ifs.open(filePath);
        std::stringstream shaderCodeStream;

        shaderCodeStream << ifs.rdbuf();
        ifs.close();

        rawShaderCode = shaderCodeStream.str();

    } catch(std::ifstream::failure &e) {
        std::cout << "Could not open shader file\n";
    }

    int shaderId = glCreateShader(shaderType);
    const GLchar *shaderCode = rawShaderCode.c_str();
    glShaderSource(shaderId, 1, &shaderCode, nullptr);
    glCompileShader(shaderId);

    int compileSuccessFlag;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compileSuccessFlag);
    if (!compileSuccessFlag) {
        glGetShaderInfoLog(shaderId, 512, nullptr, errorBuffer);
        std::cout << "Unable to compile shader\n" << errorBuffer << std::endl;
    }

    return shaderId;
}

