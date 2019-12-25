#include <iostream>
#include "DisplayManager.h"
#include "../tools/logger.h"

DisplayCreationStatus DisplayManager::create() {
    if (!glfwInit()) {
        log("Failed to initialized GLFW");
        return INIT_ERROR;
    }

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

    // Initialize GLEW
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        log("Failed to initialize GLEW");
        return INIT_ERROR;
    }

    // Clear key only after we do glfwGetKey on it
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

    return SUCCESS;
}

bool DisplayManager::closeRequested() {
    return glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE);
}

void DisplayManager::refresh() {
    glfwSwapBuffers(window);
}

void DisplayManager::close() {
    glfwTerminate();
}

const int DisplayManager::getWinWidth() {
    return WIN_WIDTH;
}

const int DisplayManager::getWinHeight() {
    return WIN_HEIGHT;
}
