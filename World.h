#pragma once

#include "Scene.h"
#include "Player.h"
#include <vector>

class World : public Scene {
public:
    World(const std::string& levelFile);

    void handleInput(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    const std::string& getLevelFile() const;

private:
    std::string mLevelFile;
    std::vector<Platform*> mPlatforms; 
    std::vector<Mob*> mMobs;
    Player* mPlayer;

    sf::View mCameraView;
};