#include "LevelSelectMenu.h"
#include "World.h"
#include "MainMenu.h"

LevelSelectMenu::LevelSelectMenu() : mSelectedIndex(0) {
    mFont.loadFromFile("assets/font/Adventure.otf");

    std::vector<std::string> levels = { "Level 1", "Level 2", "Level3", "Back" };
    for (size_t i = 0; i < levels.size(); ++i) {
        sf::Text text;
        text.setFont(mFont);
        text.setString(levels[i]);
        text.setCharacterSize(30);
        text.setPosition(300, 200 + i * 50);
        text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
        mOptions.push_back(text);
    }
}

void LevelSelectMenu::handleInput(sf::RenderWindow& window) {
    static sf::Clock menuSwitchClock;

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (menuSwitchClock.getElapsedTime().asMilliseconds() < 500) {
            continue;
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                mOptions[mSelectedIndex].setFillColor(sf::Color::White);
                mSelectedIndex = (mSelectedIndex > 0) ? mSelectedIndex - 1 : mOptions.size() - 1;
                mOptions[mSelectedIndex].setFillColor(sf::Color::Red);
            }
            else if (event.key.code == sf::Keyboard::Down) {
                mOptions[mSelectedIndex].setFillColor(sf::Color::White);
                mSelectedIndex = (mSelectedIndex + 1) % mOptions.size();
                mOptions[mSelectedIndex].setFillColor(sf::Color::Red);
            }
            else if (event.key.code == sf::Keyboard::Enter) {
                if (mSelectedIndex == mOptions.size() - 1) {
                    SceneManager::getInstance().changeScene(new MainMenu());
                }
                else {
                    SceneManager::getInstance().changeScene(new World("levels/Level " + std::to_string(mSelectedIndex + 1) + ".txt"));
                }

                menuSwitchClock.restart();
            }
        }
    }
}

void LevelSelectMenu::update(float deltaTime) {

}

void LevelSelectMenu::render(sf::RenderWindow& window) {
    for (sf::Text option : mOptions) {
        window.draw(option);
    }
}
