#include "PauseMenu.h"
#include "MainMenu.h"

PauseMenu::PauseMenu(Scene* currentLevel) : mSelectedIndex(0), mCurrentLevel(currentLevel) {
    if (!mFont.loadFromFile("assets/font/Adventure.otf")) {
        throw std::runtime_error("Impossible de charger la police Adventure.otf");
    }

    mTitle.setFont(mFont);
    mTitle.setString("Paused");
    mTitle.setCharacterSize(50);
    mTitle.setPosition(300, 100);

    mResume.setFont(mFont);
    mResume.setString("Resume");
    mResume.setCharacterSize(30);
    mResume.setPosition(300, 200);
    mResume.setFillColor(sf::Color::Red);

    mQuit.setFont(mFont);
    mQuit.setString("Quit to Main Menu");
    mQuit.setCharacterSize(30);
    mQuit.setPosition(300, 250);
    mQuit.setFillColor(sf::Color::White);
}

void PauseMenu::handleInput(sf::RenderWindow& window) {

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
                mSelectedIndex = 0;
                mResume.setFillColor(sf::Color::Red);
                mQuit.setFillColor(sf::Color::White);
            }
            else if (event.key.code == sf::Keyboard::Down) {
                mSelectedIndex = 1;
                mResume.setFillColor(sf::Color::White);
                mQuit.setFillColor(sf::Color::Red);
            }
            else if (event.key.code == sf::Keyboard::Enter) {
                if (mSelectedIndex == 0) {
                    SceneManager::getInstance().pushScene(mCurrentLevel);
                }
                else if (mSelectedIndex == 1) {
                    SceneManager::getInstance().changeScene(new MainMenu());
                }
            }
        }
    }
}

void PauseMenu::update(float deltaTime) {

}

void PauseMenu::render(sf::RenderWindow& window) {
    window.setView(window.getDefaultView());
    window.draw(mTitle);
    window.draw(mResume);
    window.draw(mQuit);
}
