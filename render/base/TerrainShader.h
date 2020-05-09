//
// Created by Paul D'Pong on 2020-05-09.
//

#ifndef ENGINE_TERRAINSHADER_H
#define ENGINE_TERRAINSHADER_H


#include "Shader.h"
#include "../entities/Light.h"
#include "Material.h"

class TerrainShader : public Shader {
public:
    TerrainShader();
    void loadTransformationMatrix(mat4 matrix);
    void loadViewMatrix(mat4 matrix);
    void loadProjectionMatrix(mat4 matrix);
    void loadLight(Light light);
    void loadMaterial(Material material);
    void getUniformLocations() override;
private:
    int uLoc_transformationMatrix = 0;
    int uLoc_viewMatrix = 0;
    int uLoc_projectionMatrix = 0;
    int uLoc_lightPos = 0;
    int uLoc_lightColor = 0;
    int uLoc_materialReflectivity = 0;
    int uLoc_materialShine = 0;
};


#endif //ENGINE_TERRAINSHADER_H
