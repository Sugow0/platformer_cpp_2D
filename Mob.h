#pragma once

#include "Entity.h"
#include "Platform.h"

class Mob : public Entity {
public:
    Mob(const sf::Sprite& sprite);

    void update(float deltaTime) override;
    void handleCollision(std::vector<Platform*>& platforms);

    void setOnGround(bool onGround);

private:
    sf::Vector2f mVelocity;
    const float mGravity = 500.0f;
    bool mOnGround = false;
};