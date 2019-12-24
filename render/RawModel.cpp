#include "RawModel.h"

RawModel::RawModel(int vaoID, int vertexCount) {
    this->vaoID = vaoID;
    this->vertexCount = vertexCount;
}

int RawModel::getVaoId() {
    return vaoID;
}

int RawModel::getVertexCount() {
    return vertexCount;
}


