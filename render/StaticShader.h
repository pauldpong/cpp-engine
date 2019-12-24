#ifndef ENGINE_STATICSHADER_H
#define ENGINE_STATICSHADER_H

#include "Shader.h"

class StaticShader : public Shader {
public:
    StaticShader();
    void loadTransformationMatrix(glm::mat4 matrix);
    void loadProjectionMatrix(glm::mat4 matrix);
    void getUniformLocations() override;
private:
    int uLTransformation = 0;
    int uLProjection = 0;
};

#endif //ENGINE_STATICSHADER_H
