#ifndef ENGINE_LIGHT_H
#define ENGINE_LIGHT_H

#include "../../includes.h"

class Light {
private:
    vec3 position;
    vec3 color;
public:
    Light(const vec3 &position, const vec3 &color);

    const vec3 &getPosition() const;

    void setPosition(const vec3 &position);

    const vec3 &getColor() const;

    void setColor(const vec3 &color);
};


#endif //ENGINE_LIGHT_H
