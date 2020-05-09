#ifndef ENGINE_MATERIAL_H
#define ENGINE_MATERIAL_H

class Material {
private:
    float reflectivity = 0;
    float shine = 1;

public:
    Material() = default;

    Material(float reflectivity, float shine);

    float getReflectivity() const;
    void setReflectivity(float reflectivity);

    float getShine() const;
    void setShine(float shine);
};


#endif //ENGINE_MATERIAL_H
