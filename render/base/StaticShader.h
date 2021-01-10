#ifndef ENGINE_STATICSHADER_H
#define ENGINE_STATICSHADER_H

#include "Shader.h"
#include "../entities/Light.h"
#include "Material.h"

class StaticShader : public Shader {
public:
    StaticShader();
    void loadTransformationMatrix(mat4 matrix);
    void loadViewMatrix(mat4 matrix);
    void loadProjectionMatrix(mat4 matrix);
    void loadLight(Light light);
    void loadFakeLighting(bool useFake);
    void loadSkyColor(float r, float g, float b);
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
    int uLoc_useFakeLighting = 0;
    int uLoc_skyColor = 0;
};

#endif //ENGINE_STATICSHADER_H
