#include "Player.h"
#include "../common/InputManager.h"
#include "../DisplayManager.h"

Player::Player(const TexturedModel &model, const glm::vec3 &position, float rx, float ry, float rz, float scale)
        : Entity(model, position, rx, ry, rz, scale) {
    InputManager* inputManager = InputManager::instance();
    inputManager->addListener(this);
}

void Player::move() {
    increaseRotation(0, currentTurnSpeed * DisplayManager::getFrameTime(), 0);

    double distance = currentSpeed * DisplayManager::getFrameTime();
    double dx = distance * sin(getRy()/180 * M_PI);
    double dz = distance * cos(getRz()/180 * M_PI);

    increasePosition(dx, 0, dz);
}

void Player::onKeyDown(int key) {
    if (key == GLFW_KEY_W) {
        currentSpeed = RUN_SPEED;
    } else if (key == GLFW_KEY_S) {
        currentSpeed = -RUN_SPEED;
    } else {
        currentSpeed = 0;
    }

    if (key == GLFW_KEY_D) {
        currentTurnSpeed = -TURN_SPEED;
    } else if (key == GLFW_KEY_A) {
        currentTurnSpeed = TURN_SPEED;
    } else {
        currentTurnSpeed = 0;
    }

    move();
}

void Player::onKeyUp(int key) {

}

void Player::onKeyHold(int key) {
}

void Player::onMouseMove(double xpos, double ypos) {

}

Player::~Player() {
    InputManager* inputManager = InputManager::instance();
    inputManager->removeListener(this);
}
