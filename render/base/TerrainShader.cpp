#include "TerrainShader.h"

TerrainShader::TerrainShader() : Shader("../shaders/terrainVertexShader.txt", "../shaders/terrainFragShader.txt") {
    getUniformLocations();
}

void TerrainShader::getUniformLocations() {
    uLoc_transformationMatrix = getUniformLocation("transformationMatrix");
    uLoc_viewMatrix = getUniformLocation("viewMatrix");
    uLoc_projectionMatrix = getUniformLocation("projectionMatrix");
    uLoc_lightPos = getUniformLocation("lightPos");
    uLoc_lightColor = getUniformLocation("lightColor");
    uLoc_materialReflectivity = getUniformLocation("reflectivity");
    uLoc_materialShine = getUniformLocation("shine");
}

void TerrainShader::loadLight(Light light) {
    loadUniformVector(uLoc_lightPos, light.getPosition());
    loadUniformVector(uLoc_lightColor, light.getColor());
}

void TerrainShader::loadMaterial(Material material) {
    loadUniformFloat(uLoc_materialReflectivity, material.getReflectivity());
    loadUniformFloat(uLoc_materialShine, material.getShine());
}

void TerrainShader::loadTransformationMatrix(mat4 matrix) {
    loadUniformMatrix(uLoc_transformationMatrix, matrix);
}

void TerrainShader::loadViewMatrix(mat4 matrix) {
    loadUniformMatrix(uLoc_viewMatrix, matrix);
}

void TerrainShader::loadProjectionMatrix(mat4 matrix) {
    loadUniformMatrix(uLoc_projectionMatrix, matrix);
}