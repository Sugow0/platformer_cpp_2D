#include "SceneManager.h"

SceneManager& SceneManager::getInstance()
{
    static SceneManager instance;
    return instance;
}

Scene* SceneManager::getCurrentScene()
{
    if (!mScenes.empty()) {
        return mScenes.back();
    }
    return nullptr;
}

void SceneManager::changeScene(Scene* newScene) {

    if (!mScenes.empty()) {
        delete mScenes.back();
        mScenes.pop_back();
    }
    mScenes.push_back(newScene);
}

void SceneManager::pushScene(Scene* newScene) {
    mScenes.push_back(newScene);
}

void SceneManager::popScene() {
    if (!mScenes.empty()) {
        delete mScenes.back();
        mScenes.pop_back();
    }
}

void SceneManager::handleInput(sf::RenderWindow& window) {
    if (!mScenes.empty()) {
        mScenes.back()->handleInput(window);
    }
}

void SceneManager::update(float deltaTime) {
    if (!mScenes.empty()) {
        mScenes.back()->update(deltaTime);
    }
}

void SceneManager::render(sf::RenderWindow& window) {
    if (!mScenes.empty()) {
        mScenes.back()->render(window);
    }
}

SceneManager::~SceneManager()
{
    for (Scene* scene : mScenes) {
        delete scene;
    }
    mScenes.clear();
}
