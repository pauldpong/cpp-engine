#ifndef ENGINE_INPUTLISTENER_H
#define ENGINE_INPUTLISTENER_H

class InputListener {
public:
    InputListener() = default;

    virtual ~InputListener() = default;

    // Keyboard
    virtual void onKeyDown(int key) = 0;
    virtual void onKeyUp(int key) = 0;
    virtual void onKeyHold(int key) = 0;

    // Mouse
    virtual void onMouseMove(double xpos, double ypos) = 0;
};

#endif //ENGINE_INPUTLISTENER_H