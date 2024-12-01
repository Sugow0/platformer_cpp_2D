#pragma once

#include "Scene.h"
#include "SceneManager.h"

class PauseMenu : public Scene {
public:
    PauseMenu(Scene* currentLevel);

    void handleInput(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font mFont;
    sf::Text mTitle;
    sf::Text mResume;
    sf::Text mQuit;
    int mSelectedIndex;
    Scene* mCurrentLevel;
};
