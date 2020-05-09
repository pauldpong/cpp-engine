#include <iostream>
#include <fstream>
#include <vector>

#include "ObjLoader.h"
#include "../../tools/logger.h"
#include "../../includes.h"

std::vector<std::string> toStringArray(const std::string string, const std::string delimiter) {
    size_t last = 0, next = 0;
    std::vector<std::string> stringArray;

    while ((next = string.find(delimiter, last)) != std::string::npos) {
        stringArray.push_back(string.substr(last, next - last));
        last = next + strlen(delimiter.data());

        if (string.find(delimiter, last) == std::string::npos) {
            stringArray.push_back(string.substr(last, strlen(string.data())));
        }
    }

    return stringArray;
}

RawModel ObjLoader::loadObjModel(const std::string path, Loader loader) {

    std::ifstream objFile;
    objFile.open(path);

    if (objFile.is_open()) {
        std::string line;
        std::vector<vec3> vertices, normals;
        std::vector<int> indices;
        std::vector<vec2> uvs;

        while (getline(objFile, line)) {
            std::vector<std::string> lineArray = toStringArray(line, " ");

            int index = 0;
            if (lineArray.front() == "v") {
                vec3 vertex;
                for (auto it = lineArray.begin() + 1; it != lineArray.end(); index++, it++) {
                    vertex[index] = std::stof(*it);
                }

                vertices.push_back(vertex);
            } else if (lineArray.front() == "vt") {
                vec2 uv;
                for (auto it = lineArray.begin() + 1; it != lineArray.end(); index++, it++) {
                    uv[index] = std::stof(*it);
                }

                uvs.push_back(uv);
            } else if (lineArray.front() == "vn") {
                vec3 normal;
                for (auto it = lineArray.begin() + 1; it != lineArray.end(); index++, it++) {
                    normal[index] = std::stof(*it);
                }

                normals.push_back(normal);
            } else if (lineArray.front() == "f") {
                break;
            }
        }

        std::vector<float> verticesVector(vertices.size() * 3), uvsVector(vertices.size() * 2), normalsVector(vertices.size() * 3);

        while (!objFile.eof()) {
            std::vector<std::string> lineArray = toStringArray(line, " ");

            if (lineArray.front() == "f") {
                for (auto vertexIt = lineArray.begin() + 1; vertexIt != lineArray.end(); vertexIt++) {
                    std::vector<std::string> faceVertexArray = toStringArray(*vertexIt, "/");

                    int currentVertexIndex = std::stoi(faceVertexArray[0]) - 1;
                    indices.push_back(currentVertexIndex);

                    vec2 currentTexture = uvs[std::stoi(faceVertexArray[1]) - 1];
                    uvsVector.at(currentVertexIndex * 2) = currentTexture.x;
                    uvsVector.at(currentVertexIndex * 2 + 1) = 1 - currentTexture.y;

                    vec3 currentNormal = normals[std::stoi(faceVertexArray[2]) - 1];
                    normalsVector[currentVertexIndex * 3] = currentNormal.x;
                    normalsVector[currentVertexIndex * 3 + 1] = currentNormal.y;
                    normalsVector[currentVertexIndex * 3 + 2] = currentNormal.z;
                }
            }

            getline(objFile, line);
        }

        objFile.close();

        int index = 0;
        for (auto it = vertices.begin(); it != vertices.end(); index+=3, it++) {
            verticesVector[index] = it->x;
            verticesVector[index + 1] = it->y;
            verticesVector[index + 2] = it->z;
        }

        return loader.loadToVao(verticesVector, uvsVector, normalsVector, indices);
    } else {
        log("Unable to open OBJ file");
    }

    return RawModel(0, 0);
}
