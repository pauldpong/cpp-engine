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

Material::Material(float reflectivity, float shine) : reflectivity(reflectivity), shine(shine) {}
