#pragma once

#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual ~Scene() = default;

    virtual void handleInput(sf::RenderWindow& window) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};
