#include "MainMenu.h"
#include "LevelSelectMenu.h"

MainMenu::MainMenu() : mSelectedIndex(0) {
    mFont.loadFromFile("assets/font/Adventure.otf");

    mTitle.setFont(mFont);
    mTitle.setString("Main Menu");
    mTitle.setCharacterSize(50);
    mTitle.setPosition(300, 100);

    mStartGame.setFont(mFont);
    mStartGame.setString("Start Game");
    mStartGame.setCharacterSize(30);
    mStartGame.setPosition(300, 200);
    mStartGame.setFillColor(sf::Color::Red);

    mExit.setFont(mFont);
    mExit.setString("Exit");
    mExit.setCharacterSize(30);
    mExit.setPosition(300, 250);
    mExit.setFillColor(sf::Color::White);
}

void MainMenu::handleInput(sf::RenderWindow& window) {
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
                mStartGame.setFillColor(sf::Color::Red);
                mExit.setFillColor(sf::Color::White);
            }
            else if (event.key.code == sf::Keyboard::Down) {
                mSelectedIndex = 1;
                mStartGame.setFillColor(sf::Color::White);
                mExit.setFillColor(sf::Color::Red);
            }
            else if (event.key.code == sf::Keyboard::Enter) {
                if (mSelectedIndex == 0) {
                    SceneManager::getInstance().changeScene(new LevelSelectMenu());
                }
                else if (mSelectedIndex == 1) {
                    window.close();
                }

                menuSwitchClock.restart();
            }
        }
    }
}

void MainMenu::update(float deltaTime) {

}

void MainMenu::render(sf::RenderWindow& window) {
    window.draw(mTitle);
    window.draw(mStartGame);
    window.draw(mExit);
}
