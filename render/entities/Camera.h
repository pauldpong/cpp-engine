#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H

#include "../../includes.h"
#include "../common/InputListener.h"
#include "../DisplayManager.h"

class Camera : private InputListener {
private:
    vec3 position = vec3(0, 0, 4);
    vec3 front = vec3(0, 0, -1.0f);
    vec3 up = vec3(0, 1.0f, 0);
    vec3 right = glm::cross(front, up);

    vec3 WorldUp = up;

    float yaw = -90.0f, pitch = 0;

    float lastX = DisplayManager::getWinWidth() / 2.0f;
    float lastY = DisplayManager::getWinHeight() / 2.0f;

    float speed = 3.0f; //Camera movement speed
    float mouseSensitivity = 0.1f;

    void updateCameraVectors();

public:
    Camera();
    ~Camera() override;
    mat4 getViewMatrix();

private:
    void onKeyDown(int key) override;

    void onKeyUp(int key) override;

    void onKeyHold(int key) override;

    void onMouseMove(double xpos, double ypos) override;
};


#endif //ENGINE_CAMERA_H
