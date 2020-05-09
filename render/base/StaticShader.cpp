#include "StaticShader.h"

StaticShader::StaticShader() : Shader("../shaders/vertexShader.txt", "../shaders/fragmentShader.txt") {
    getUniformLocations();
}

void StaticShader::getUniformLocations() {
    uLoc_transformationMatrix = getUniformLocation("transformationMatrix");
    uLoc_viewMatrix = getUniformLocation("viewMatrix");
    uLoc_projectionMatrix = getUniformLocation("projectionMatrix");
    uLoc_lightPos = getUniformLocation("lightPos");
    uLoc_lightColor = getUniformLocation("lightColor");
    uLoc_materialReflectivity = getUniformLocation("reflectivity");
    uLoc_materialShine = getUniformLocation("shine");
}

void StaticShader::loadLight(Light light) {
    loadUniformVector(uLoc_lightPos, light.getPosition());
    loadUniformVector(uLoc_lightColor, light.getColor());
}

void StaticShader::loadMaterial(Material material) {
    loadUniformFloat(uLoc_materialReflectivity, material.getReflectivity());
    loadUniformFloat(uLoc_materialShine, material.getShine());
}

void StaticShader::loadTransformationMatrix(mat4 matrix) {
    loadUniformMatrix(uLoc_transformationMatrix, matrix);
}

void StaticShader::loadViewMatrix(mat4 matrix) {
    loadUniformMatrix(uLoc_viewMatrix, matrix);
}

void StaticShader::loadProjectionMatrix(mat4 matrix) {
    loadUniformMatrix(uLoc_projectionMatrix, matrix);
}

