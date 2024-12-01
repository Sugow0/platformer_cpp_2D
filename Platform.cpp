#include "Platform.h"

Platform::Platform(const sf::Sprite& sprite) : Entity(sprite) {}

void Platform::update(float deltaTime) {

}

bool Platform::checkCollision(const Entity& entity) const {
    return mSprite.getGlobalBounds().intersects(entity.getHitbox());
}
