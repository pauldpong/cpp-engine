#ifndef ENGINE_RAWMODEL_H
#define ENGINE_RAWMODEL_H

// Representation of the VAO object in memory

class RawModel {
private:
    int vaoID;
    int vertexCount;

public:
    RawModel(int vaoID, int vertexCount);

    int getVaoId() const;

    int getVertexCount() const;
};

#endif //ENGINE_RAWMODEL_H
