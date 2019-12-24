#include "StaticShader.h"

StaticShader::StaticShader() : Shader("../shaders/vertexShader.txt", "../shaders/fragmentShader.txt") {}

void StaticShader::getUniformLocations() {
    uLTransformation = getUniformLocation("transformationMatrix");
    uLProjection = getUniformLocation("projectionMatrix");
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix) {
    loadUniformMatrix(uLTransformation, matrix);
}

void StaticShader::loadProjectionMatrix(glm::mat4 matrix) {
    loadUniformMatrix(uLProjection, matrix);
}
