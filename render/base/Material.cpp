#include "Material.h"

float Material::getReflectivity() const {
    return reflectivity;
}

void Material::setReflectivity(float reflectivity) {
    Material::reflectivity = reflectivity;
}

float Material::getShine() const {
    return shine;
}

void Material::setShine(float shine) {
    Material::shine = shine;
}

bool Material::isTransparent() const {
    return transparent;
}

void Material::setTransparent(bool value) {
    transparent = value;
}

bool Material::useFakeLighting() const {
    return fakeLighting;
}

void Material::setFakeLighting(bool value) {
    fakeLighting = value;
}

Material::Material(float reflectivity, float shine) : reflectivity(reflectivity), shine(shine) {}
