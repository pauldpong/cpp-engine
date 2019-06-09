#include <iostream>
#include "DisplayManager.h"

DisplayCreationStatus DisplayManager::create() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Engine", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return INIT_ERROR;
    }
    glfwMakeContextCurrent(window);
    glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initalize GLEW" << std::endl;

        return INIT_ERROR;
    }

    return SUCCESS;
}

bool DisplayManager::closeRequested() {
    return glfwWindowShouldClose(window);
}

void DisplayManager::refresh() {
    glfwSwapBuffers(window);
}

void DisplayManager::close() {
    glfwTerminate();
}

int DisplayManager::getWindowWidth() {
    return WIN_WIDTH;
}

int DisplayManager::getWindowHeight() {
    return WIN_HEIGHT;
}