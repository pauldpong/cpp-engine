#include "../tools/logger.h"
#include "common/InputManager.h"

#include "DisplayManager.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseCallback(GLFWwindow* window, double xpos, double ypos);

DisplayManager::DisplayManager(std::string title) : title(std::move(title)) {}

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

    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, title.data(), nullptr, nullptr);
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

    // Disables cursor
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set I/O callbacks
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, mouseCallback);

    return SUCCESS;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    InputManager* inputManager = InputManager::instance();
    inputManager->handleKeyPress(key, action);
}

void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    InputManager* inputManager = InputManager::instance();
    inputManager->handleMouse(xpos, ypos);
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
