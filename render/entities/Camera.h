//
// Created by Paul D'Pong on 2019-12-24.
//

#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H

#include "../../includes.h"

class Camera {
private:
    glm::vec3 position = glm::vec3(0, 0, 0);
    float pitch, yaw, roll;
public:
    Camera();

    const glm::vec3 &getPosition() const;

    float getPitch() const;

    float getYaw() const;

    float getRoll() const;
};


#endif //ENGINE_CAMERA_H
