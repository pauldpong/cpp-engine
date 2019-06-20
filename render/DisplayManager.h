#ifndef ENGINE_DISPLAYMANAGER_H
#define ENGINE_DISPLAYMANAGER_H

#include "../includes.h"

enum DisplayCreationStatus {
    INIT_ERROR = 0,
    SUCCESS
};

class DisplayManager {
private:
    const static int WIN_WIDTH = 800;
    const static int WIN_HEIGHT = 600;

    GLFWwindow* window = nullptr;

public:
    DisplayCreationStatus create();
    bool closeRequested();
    void refresh();
    void close();

    int getWindowWidth();
    int getWindowHeight();
};


#endif //ENGINE_DISPLAYMANAGER_H
