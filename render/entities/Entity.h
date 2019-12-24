//
// Created by Paul D'Pong on 2019-12-23.
//

#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include "../../includes.h"
#include "../TexturedModel.h"

class Entity {
private:
    TexturedModel model;
    glm::vec3 position;
    float rx, ry, rz;
    float scale;
public:
    Entity(const TexturedModel &model, const glm::vec3 &position, float rx, float ry, float rz, float scale);

    const TexturedModel &getModel() const;

    void setModel(const TexturedModel &model);

    const glm::vec3 &getPosition() const;

    void setPosition(const glm::vec3 &position);

    float getRx() const;

    void setRx(float rx);

    float getRy() const;

    void setRy(float ry);

    float getRz() const;

    void setRz(float rz);

    float getScale() const;

    void setScale(float scale);

    void increasePosition(float dx, float dy, float dz);
    void increaseRotation(float dx, float dy, float dz);
};


#endif //ENGINE_ENTITY_H
