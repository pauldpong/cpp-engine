#ifndef ENGINE_PLAYER_H
#define ENGINE_PLAYER_H

#include "Entity.h"
#include "../common/InputListener.h"

class Player : public Entity, private InputListener {
private:
    static constexpr float RUN_SPEED = 20; // units/secs
    static constexpr float TURN_SPEED = 160; // degs/secs

    float currentSpeed = 0;
    float currentTurnSpeed = 0;

    void onKeyDown(int key) override;

    void onKeyUp(int key) override;

    void onKeyHold(int key) override;

    void onMouseMove(double xpos, double ypos) override;

public:
    Player(const TexturedModel &model, const glm::vec3 &position, float rx, float ry, float rz, float scale);
    ~Player() override;

    void move();
};

#endif //ENGINE_PLAYER_H