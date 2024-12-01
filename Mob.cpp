#include "Mob.h"

Mob::Mob(const sf::Sprite& sprite) : Entity(sprite), mVelocity(0.0f, 0.0f) {

    getHitbox();
}

void Mob::update(float deltaTime) {
    if (!mOnGround) {
        mVelocity.y += mGravity * deltaTime;

        if (mVelocity.y > 1000.0f) {
            mVelocity.y = 1000.0f;
        }
    }

    mSprite.move(mVelocity * deltaTime);

    mOnGround = false;
}



void Mob::setOnGround(bool onGround) {
    mOnGround = onGround;
    if (onGround) {
        mVelocity.y = 0.0f;
    }
}

void Mob::handleCollision(std::vector<Platform*>& platforms) {
    for (Platform* platform : platforms) {
        if (platform->checkCollision(*this)) {
            sf::FloatRect platformBounds = platform->getHitbox();
            sf::FloatRect mobBounds = getHitbox();

            if (mobBounds.top + mobBounds.height <= platformBounds.top + 5.0f) {
                setPosition({ getPosition().x, platformBounds.top - mobBounds.height });
                setOnGround(true);
                return;
            }
        }
    }

    setOnGround(false);
}
