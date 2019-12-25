#ifndef ENGINE_STATICSHADER_H
#define ENGINE_STATICSHADER_H

#include "Shader.h"

class StaticShader : public Shader {
public:
    StaticShader();
    void loadMVP(glm::mat4 matrix);
    void getUniformLocations() override;
private:
    int uLoc_MVP = 0;
};

#endif //ENGINE_STATICSHADER_H
