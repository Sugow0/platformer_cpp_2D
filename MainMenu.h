#pragma once

#include "Scene.h"
#include "SceneManager.h"

class MainMenu : public Scene {
public:
    MainMenu();

    void handleInput(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font mFont;
    sf::Text mTitle;
    sf::Text mStartGame;
    sf::Text mExit;
    int mSelectedIndex;
};
