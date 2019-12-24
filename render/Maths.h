#ifndef ENGINE_MATHS_H
#define ENGINE_MATHS_H

#include "../includes.h"
#include "../includes/glm/gtc/matrix_transform.hpp"
#include "../includes/glm/gtc/type_ptr.hpp"
#include <math.h>

class Maths {
public:
    static glm::mat4 createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale);
    static float toRadian(float degrees);
private:
    Maths() = default;
};


#endif //ENGINE_MATHS_H
