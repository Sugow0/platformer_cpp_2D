#pragma once

#include "Entity.h"
#include "Platform.h"
#include "Mob.h"

class Player : public Entity {
public:
    Player(const sf::Sprite& sprite);

    void handleInput(sf::RenderWindow& window);
    void update(float deltaTime) override;
    void handleCollision(std::vector<Platform*>& platforms);
    void handleCollisionWithMobs(std::vector<Mob*>& mobs, std::string currentScene);



    void setOnGround(bool onGround);

private:
    sf::Vector2f mVelocity;
    const float mGravity = 500.0f;
    bool mOnGround = false;
    
};
