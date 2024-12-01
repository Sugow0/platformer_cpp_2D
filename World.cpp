#include <iostream>
#include <fstream>
#include <sstream>


#include "World.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "PauseMenu.h"
#include "DeathMenu.h"



World::World(const std::string& levelFile) : mLevelFile(levelFile) {
    std::ifstream file(mLevelFile);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible de charger le niveau depuis " << mLevelFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string entityType;
        float x, y, width, height;
        std::istringstream iss(line);
        if (!(iss >> entityType >> x >> y >> width >> height)) {
            std::cerr << "Erreur de format dans le fichier de niveau : " << line << std::endl;
            continue;
        }

        

        if (entityType == "PLATFORMS") {
            sf::Sprite platformSprite = ResourceManager::getInstance().getSpritePlatform();


            platformSprite.setPosition(x, y);
            platformSprite.setScale(width, height);
            Platform *platform = new Platform(platformSprite);
            mPlatforms.push_back(platform);
        }

        if (entityType == "PLAYER_START") {
            sf::Sprite playerSprite = ResourceManager::getInstance().getSpritePlayer();
            playerSprite.setPosition(x, y);
            mPlayer = new Player(playerSprite);
        }

        if (entityType == "MOB_START") {
            sf::Sprite mobSprite = ResourceManager::getInstance().getSpriteMob();
            mobSprite.setPosition(x, y);
            Mob* mob = new Mob(mobSprite);
            mMobs.push_back(mob);
        }

        
    }

    file.close();

    mCameraView = sf::View(sf::FloatRect(0, 0, 200, 100));
    mCameraView.setCenter(mPlayer->getPosition().x, mPlayer->getPosition().y);

}


void World::handleInput(sf::RenderWindow& window) {

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
            if (event.key.code == sf::Keyboard::Escape) {

                Scene* mCurrentScene = SceneManager::getInstance().getCurrentScene();
                PauseMenu* pauseMenu = new PauseMenu(mCurrentScene);
                SceneManager::getInstance().changeScene(pauseMenu);

            }
        }

        mPlayer->handleInput(window);
    }
}

void World::update(float deltaTime) {
    mPlayer->update(deltaTime);
    mPlayer->handleCollision(mPlatforms);

    for (Mob* mob: mMobs) {
        mob->update(deltaTime);
        mob->handleCollision(mPlatforms);
    }

    mPlayer->handleCollisionWithMobs(mMobs, mLevelFile);

    sf::Vector2f playerPosition = mPlayer->getPosition();
    mCameraView.setCenter(playerPosition.x, mCameraView.getCenter().y);

    if (playerPosition.y > mCameraView.getCenter().y + mCameraView.getSize().y / 2) {
        SceneManager::getInstance().changeScene(new DeathMenu(mLevelFile));
    }
}


void World::render(sf::RenderWindow& window) {
    window.setView(mCameraView);

    for (Platform* platform : mPlatforms) {
        platform->render(window);
    }

    if (mPlayer) {
        mPlayer->render(window);
    }

    for (Mob* mob : mMobs) {
        mob->render(window);
    }
}

const std::string& World::getLevelFile() const {
    return mLevelFile;
}


