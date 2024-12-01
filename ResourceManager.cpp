#include "ResourceManager.h"
#include <stdexcept>
#include <iostream>

ResourceManager& ResourceManager::getInstance() {
    static ResourceManager instance;
    return instance;
}

sf::Texture& ResourceManager::getTexture(const std::string& filename) {
    for (size_t i = 0; i < mTextures.size(); ++i) {
        if (mTextures[i].filename == filename) {
            return mTextures[i].texture;
        }
    }
    TextureResource newResource;
    newResource.filename = filename;

    if (!newResource.texture.loadFromFile(filename)) {
        throw std::runtime_error("Impossible de charger la texture : " + filename);
    }

    mTextures.push_back(newResource);
    return mTextures[mTextures.size() - 1].texture;
}

sf::Sprite ResourceManager::getSpritePlatform() {
    sf::Texture& texture = getTexture("assets/tilemap/tilemap.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(24, 24, 24, 8));
    return sprite;
}

sf::Sprite ResourceManager::getSpritePlayer() {
    sf::Texture& texture = getTexture("assets/tilemap/tilemap.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 48, 8, 8));
    return sprite;
}

sf::Sprite ResourceManager::getSpriteMob() {
    sf::Texture& texture = getTexture("assets/tilemap/tilemap.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(32, 56, 8, 8));
    return sprite;
}
