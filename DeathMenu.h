#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "World.h"

class DeathMenu : public Scene {
public:
    DeathMenu(std::string currentLevelFile);

    void handleInput(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font mFont;
    sf::Text mTitle;
    sf::Text mRestart;
    sf::Text mMainMenu;
    int mSelectedIndex;
    std::string  mCurrentLevel;
};

