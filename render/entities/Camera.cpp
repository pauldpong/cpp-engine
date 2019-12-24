//
// Created by Paul D'Pong on 2019-12-24.
//

#include "Camera.h"

Camera::Camera() {}

const glm::vec3 &Camera::getPosition() const {
    return position;
}

float Camera::getPitch() const {
    return pitch;
}

float Camera::getYaw() const {
    return yaw;
}

float Camera::getRoll() const {
    return roll;
}