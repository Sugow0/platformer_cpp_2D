#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity {
public:
    Entity(const sf::Sprite& sprite);
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window);

    const sf::Sprite& getSprite() const;
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;


    sf::FloatRect getHitbox() const;
    void setCustomHitbox(const sf::FloatRect& hitbox);

protected:
    sf::Sprite mSprite;
    sf::FloatRect mCustomHitbox;
    bool mUseCustomHitbox = false;
};
