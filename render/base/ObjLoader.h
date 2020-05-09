#ifndef ENGINE_OBJLOADER_H
#define ENGINE_OBJLOADER_H

#include <string>

#include "RawModel.h"
#include "../Loader.h"

class ObjLoader {
public:
    static RawModel loadObjModel(std::string path, Loader loader);
};


#endif //ENGINE_OBJLOADER_H
