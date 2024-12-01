#include "Entity.h"

Entity::Entity(const sf::Sprite& sprite) : mSprite(sprite) {}

void Entity::render(sf::RenderWindow& window) {
    window.draw(mSprite);
}

const sf::Sprite& Entity::getSprite() const {
    return mSprite;
}

void Entity::setPosition(const sf::Vector2f& position) {
    mSprite.setPosition(position);
}

sf::Vector2f Entity::getPosition() const {
    return mSprite.getPosition();
}

sf::FloatRect Entity::getHitbox() const {
    if (mUseCustomHitbox) {
        return sf::FloatRect(
            mSprite.getPosition().x + mCustomHitbox.left,
            mSprite.getPosition().y + mCustomHitbox.top,
            mCustomHitbox.width,
            mCustomHitbox.height
        );
    }
    else {
        return mSprite.getGlobalBounds();
    }
}

void Entity::setCustomHitbox(const sf::FloatRect& hitbox) {
    mCustomHitbox = hitbox;
    mUseCustomHitbox = true;
}