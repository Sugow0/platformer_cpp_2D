#include "Player.h"
#include "SceneManager.h"
#include "DeathMenu.h"

Player::Player(const sf::Sprite& sprite) : Entity(sprite), mVelocity(0.0f, 0.0f) {
    
    getHitbox();
}

void Player::handleInput(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        mVelocity.x = -100.0f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        mVelocity.x = 100.0f;
    }
    else {
        mVelocity.x = 0.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && mOnGround) {
        mVelocity.y = -200.0f;
        mOnGround = false;
    }
}

void Player::update(float deltaTime) {
    if (!mOnGround) {
        mVelocity.y += mGravity * deltaTime;

        if (mVelocity.y > 1000.0f) {
            mVelocity.y = 1000.0f;
        }
    }

    mSprite.move(mVelocity * deltaTime);

    mOnGround = false;
}



void Player::setOnGround(bool onGround) {
    mOnGround = onGround;
    if (onGround) {
        mVelocity.y = 0.0f;
    }
}

void Player::handleCollision(std::vector<Platform*>& platforms) {
    for (Platform* platform : platforms) {
        if (platform->checkCollision(*this)) {
            sf::FloatRect platformBounds = platform->getHitbox();
            sf::FloatRect playerBounds = getHitbox();

            if (playerBounds.top + playerBounds.height <= platformBounds.top + 5.0f) {
                setPosition({ getPosition().x, platformBounds.top - playerBounds.height });
                setOnGround(true);
                return;
            }
        }
    }

    setOnGround(false);
}

void Player::handleCollisionWithMobs(std::vector<Mob*>& mobs, std::string currentScene) {
    sf::FloatRect playerBounds = getHitbox();

    for (size_t i = 0; i < mobs.size(); ) {
        Mob* mob = mobs[i];
        sf::FloatRect mobBounds = mob->getHitbox();

        if (playerBounds.intersects(mobBounds)) {
            if (playerBounds.top + playerBounds.height <= mobBounds.top + 5.0f) {
                delete mob;
                mobs.erase(mobs.begin() + i);
            }
            else {
                SceneManager::getInstance().changeScene(new DeathMenu(currentScene));
                return;
            }
        }
        else {
            ++i;
        }
    }
}



