#ifndef ENGINE_INPUTMANAGER_H
#define ENGINE_INPUTMANAGER_H

#include <unordered_set>
#include "InputListener.h"

class InputManager {
    static InputManager* sInstance;
    InputManager() = default;

public:
    static InputManager* instance();

    void addListener(InputListener* listener);
    void removeListener(InputListener* listener);

    void handleKeyPress(int key, int action);
    void handleMouse(double xpos, double ypos);

private:
    std::unordered_set<InputListener*> mListeners;
};

#endif //ENGINE_INPUTMANAGER_H