#include "Entity.h"

Entity::Entity(const TexturedModel &model, const glm::vec3 &position, float rx, float ry, float rz, float scale)
        : model(model), position(position), rx(rx), ry(ry), rz(rz), scale(scale) {}

const TexturedModel &Entity::getModel() const {
    return model;
}

void Entity::setModel(const TexturedModel &model) {
    Entity::model = model;
}

const glm::vec3 &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const glm::vec3 &position) {
    Entity::position = position;
}

float Entity::getRx() const {
    return rx;
}

void Entity::setRx(float rx) {
    Entity::rx = rx;
}

float Entity::getRy() const {
    return ry;
}

void Entity::setRy(float ry) {
    Entity::ry = ry;
}

float Entity::getRz() const {
    return rz;
}

void Entity::setRz(float rz) {
    Entity::rz = rz;
}

float Entity::getScale() const {
    return scale;
}

void Entity::setScale(float scale) {
    Entity::scale = scale;
}

void Entity::increaseRotation(float dx, float dy, float dz) {
    rx += dx;
    ry += dy;
    rz += dz;
}

void Entity::increasePosition(float dx, float dy, float dz) {
    position.x += dx;
    position.y += dy;
    position.z += dz;
}
