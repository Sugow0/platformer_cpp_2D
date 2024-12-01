#pragma once

#include "Entity.h"

class Platform : public Entity {
public:
    explicit Platform(const sf::Sprite& sprite);

    void update(float deltaTime) override;
    bool checkCollision(const Entity& entity) const;

private:
    sf::RectangleShape mShape;
};
