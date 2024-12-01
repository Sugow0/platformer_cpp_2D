#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "MainMenu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer Game");

    SceneManager::getInstance().changeScene(new MainMenu());

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();

        SceneManager::getInstance().handleInput(window);
        SceneManager::getInstance().update(elapsed.asSeconds());

        window.clear();
        SceneManager::getInstance().render(window);
        window.display();
    }

    return 0;
}

