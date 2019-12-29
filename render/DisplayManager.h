#ifndef ENGINE_DISPLAYMANAGER_H
#define ENGINE_DISPLAYMANAGER_H

#include "../includes.h"
#include "common/InputListener.h"


enum DisplayCreationStatus {
    INIT_ERROR = -1,
    SUCCESS
};

class DisplayManager {
private:
    const static int WIN_WIDTH = 1024;
    const static int WIN_HEIGHT = 768;

    GLFWwindow* window = nullptr;

public:
    DisplayCreationStatus create();
    bool closeRequested();
    void refresh();

    static void close();
    static const int getWinWidth();
    static const int getWinHeight();
};


#endif //ENGINE_DISPLAYMANAGER_H
