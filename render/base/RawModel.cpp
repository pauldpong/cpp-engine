#include "RawModel.h"

RawModel::RawModel(int vaoID, int vertexCount) {
    this->vaoID = vaoID;
    this->vertexCount = vertexCount;
}

int RawModel::getVertexCount() const {
    return vertexCount;
}

int RawModel::getVaoId() const {
    return vaoID;
}


