#include <iostream>
#include "DisplayManager.h"
#include "../tools/logger.h"

DisplayCreationStatus DisplayManager::create() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Engine", nullptr, nullptr);
    if (window == nullptr) {
        log("Failed to create GLFW Window");
        glfwTerminate();

        return INIT_ERROR;
    }
    glfwMakeContextCurrent(window);

    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    glViewport(0, 0, screenWidth, screenHeight);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        log("Failed to initialize GLEW");
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