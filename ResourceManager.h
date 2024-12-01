#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>

class ResourceManager {
public:
    static ResourceManager& getInstance();
    sf::Texture& getTexture(const std::string& filename);

    
    sf::Sprite getSpritePlatform();
    sf::Sprite getSpritePlayer();
    sf::Sprite getSpriteMob();

private:
    ResourceManager() = default;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    struct TextureResource {
        std::string filename;
        sf::Texture texture;
    };

    std::vector<TextureResource> mTextures;
};
