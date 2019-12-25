#include "StaticShader.h"

StaticShader::StaticShader() : Shader("../shaders/vertexShader.txt", "../shaders/fragmentShader.txt") {}

void StaticShader::getUniformLocations() {
    uLoc_MVP = getUniformLocation("MVP");
}

void StaticShader::loadMVP(glm::mat4 matrix) {
    loadUniformMatrix(uLoc_MVP, matrix);
}

