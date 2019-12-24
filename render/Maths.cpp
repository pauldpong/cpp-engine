#include "Maths.h"

float toRadian(float degrees);

glm::mat4 Maths::createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale) {
    glm::mat4 transformationMat = glm::mat4(1.0f);
    transformationMat = glm::translate(transformationMat, translation);
    transformationMat = glm::rotate(transformationMat, toRadian(rx), glm::vec3(1.0f, 0, 0));
    transformationMat = glm::rotate(transformationMat, toRadian(ry), glm::vec3(0, 1.0f, 0));
    transformationMat = glm::rotate(transformationMat, toRadian(rz), glm::vec3(0, 0, 1.0f));
    transformationMat = glm::scale(transformationMat, glm::vec3(scale, scale, scale));

    return transformationMat;
}

float Maths::toRadian(float degrees) {
    return (degrees * M_PI) / 180.0f;
}
