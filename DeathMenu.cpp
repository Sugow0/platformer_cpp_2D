#include "DeathMenu.h"
#include "MainMenu.h"

DeathMenu::DeathMenu(std::string currentLevelFile) : mSelectedIndex(0), mCurrentLevel(currentLevelFile){
    if (!mFont.loadFromFile("assets/font/Adventure.otf")) {
        throw std::runtime_error("Impossible de charger la police Adventure.otf");
    }

    mTitle.setFont(mFont);
    mTitle.setString("You Died");
    mTitle.setCharacterSize(50);
    mTitle.setPosition(300, 100);

    mRestart.setFont(mFont);
    mRestart.setString("Restart Level");
    mRestart.setCharacterSize(30);
    mRestart.setPosition(300, 200);
    mRestart.setFillColor(sf::Color::Red);

    mMainMenu.setFont(mFont);
    mMainMenu.setString("Main Menu");
    mMainMenu.setCharacterSize(30);
    mMainMenu.setPosition(300, 250);
    mMainMenu.setFillColor(sf::Color::White);
}

void DeathMenu::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                mSelectedIndex = 0;
                mRestart.setFillColor(sf::Color::Red);
                mMainMenu.setFillColor(sf::Color::White);
            }
            else if (event.key.code == sf::Keyboard::Down) {
                mSelectedIndex = 1;
                mRestart.setFillColor(sf::Color::White);
                mMainMenu.setFillColor(sf::Color::Red);
            }
            else if (event.key.code == sf::Keyboard::Enter) {
                if (mSelectedIndex == 0) {
                    SceneManager::getInstance().changeScene(new World(mCurrentLevel));
                }
                else if (mSelectedIndex == 1) {
                    SceneManager::getInstance().changeScene(new MainMenu());
                }
            }
        }
    }
}

void DeathMenu::update(float deltaTime) {

}

void DeathMenu::render(sf::RenderWindow& window) {
    window.setView(window.getDefaultView());
    window.draw(mTitle);
    window.draw(mRestart);
    window.draw(mMainMenu);
}
