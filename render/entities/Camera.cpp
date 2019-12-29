//
// Created by Paul D'Pong on 2019-12-24.
//

#include "Camera.h"
#include "../DisplayManager.h"
#include "../common/InputManager.h"

extern float deltaTime;

Camera::Camera() {
    InputManager* inputManager = InputManager::instance();
    inputManager->addListener(this);

    updateCameraVectors();
}

Camera::~Camera() {
    InputManager* inputManager = InputManager::instance();
    inputManager->removeListener(this);
}

mat4 Camera::getViewMatrix() {
    return lookAt(
            position,
            position + front,
            up
    );
}

void Camera::onKeyDown(int key) {
    if (key == GLFW_KEY_W) {
        position += front * deltaTime * speed;
    }

    if (key == GLFW_KEY_A) {
        position -= right * deltaTime * speed;
    }

    if (key == GLFW_KEY_S) {
        position -= front * deltaTime * speed;
    }

    if (key == GLFW_KEY_D) {
        position += right * deltaTime * speed;
    }
}

void Camera::onKeyUp(int key) {

}

void Camera::onKeyHold(int key) {
    if (key == GLFW_KEY_W) {
        position += front * deltaTime * speed;
    }

    if (key == GLFW_KEY_A) {
        position -= right * deltaTime * speed;
    }

    if (key == GLFW_KEY_S) {
        position -= front * deltaTime * speed;
    }

    if (key == GLFW_KEY_D) {
        position += right * deltaTime * speed;
    }
}

void Camera::onMouseMove(double xpos, double ypos) {
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates range from bottom to top
    lastX = xpos;
    lastY = ypos;

    xoffset *= mouseSensitivity;
    yoffset *= mouseSensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    updateCameraVectors();
}

void Camera::updateCameraVectors() {
    glm::vec3 newFront = vec3(
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch))
    );

    front = glm::normalize(newFront);
    // Also re-calculate the Right and Up vector
    right = glm::normalize(glm::cross(newFront, WorldUp));
    up    = glm::normalize(glm::cross(right, newFront));
}
