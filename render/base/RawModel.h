#ifndef ENGINE_RAWMODEL_H
#define ENGINE_RAWMODEL_H

// Representation of the VAO object in memory

class RawModel {
private:
    int vaoID;
    int vertexCount;

public:
    RawModel(int vaoID, int vertexCount);
    int getVaoId();
    int getVertexCount();
};

#endif //ENGINE_RAWMODEL_H
