#ifndef ENGINE_DISPLAYMANAGER_H
#define ENGINE_DISPLAYMANAGER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

enum DisplayCreationStatus {
    INIT_ERROR = -1,
    SUCCESS
};

class DisplayManager {
private:
    GLFWwindow* window = nullptr;

    const static int WIN_WIDTH = 1024;
    const static int WIN_HEIGHT = 768;
    std::string title = "Untitled";

public:
    DisplayManager() = default;
    explicit DisplayManager(std::string title);

    DisplayCreationStatus create();
    bool closeRequested();
    void refresh();

    static void close();
    static const int getWinWidth();
    static const int getWinHeight();
};

#endif //ENGINE_DISPLAYMANAGER_H
