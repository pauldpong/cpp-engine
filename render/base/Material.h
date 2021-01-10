#ifndef ENGINE_MATERIAL_H
#define ENGINE_MATERIAL_H

class Material {
private:
    float reflectivity = 0;
    float shine = 1;

    bool transparent = false;
    bool fakeLighting = false;

public:
    Material() = default;

    Material(float reflectivity, float shine);

    float getReflectivity() const;
    void setReflectivity(float reflectivity);

    float getShine() const;
    void setShine(float shine);

    bool isTransparent() const;
    void setTransparent(bool value);

    bool useFakeLighting() const;
    void setFakeLighting(bool value);
};

#endif //ENGINE_MATERIAL_H