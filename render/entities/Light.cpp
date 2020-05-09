//
// Created by Paul D'Pong on 2020-05-05.
//

#include "Light.h"

Light::Light(const vec3 &position, const vec3 &color) : position(position), color(color) {}

const vec3 &Light::getPosition() const {
    return position;
}

void Light::setPosition(const vec3 &position) {
    Light::position = position;
}

const vec3 &Light::getColor() const {
    return color;
}

void Light::setColor(const vec3 &color) {
    Light::color = color;
}
