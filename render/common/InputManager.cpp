#include <GLFW/glfw3.h>
#include "InputManager.h"

InputManager* InputManager::sInstance = nullptr;

InputManager *InputManager::instance() {
    if (!sInstance) {
        sInstance = new InputManager;
    }

    return sInstance;
}

void InputManager::handleKeyPress(int key, int action) {
    if (action == GLFW_PRESS) {
        for (auto mListener : mListeners) {
            mListener->onKeyDown(key);
        }
    }

    if (action == GLFW_REPEAT) {
        for (auto mListener : mListeners) {
            mListener->onKeyHold(key);
        }
    }

    if (action == GLFW_RELEASE) {
        for (auto mListener : mListeners) {
            mListener->onKeyUp(key);
        }
    }
}

void InputManager::handleMouse(double xpos, double ypos) {
    for (auto mListener : mListeners) {
        mListener->onMouseMove(xpos, ypos);
    }
}

void InputManager::addListener(InputListener *listener) {
    mListeners.insert(listener);
}

void InputManager::removeListener(InputListener *listener) {
    mListeners.erase(listener);
}
