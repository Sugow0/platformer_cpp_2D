#pragma once
#include "Scene.h"
#include "SceneManager.h"

class LevelSelectMenu : public Scene {
public:
    LevelSelectMenu();

    void handleInput(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font mFont;
    std::vector<sf::Text> mOptions;
    int mSelectedIndex;
};
