#pragma once

#include <memory>
#include <stack>
#include "Scene.h"

class SceneManager {
public:
    static SceneManager& getInstance();

    Scene* getCurrentScene();

    void changeScene(Scene* newScene);
    void pushScene(Scene* newScene);
    void popScene();
    void handleInput(sf::RenderWindow& window);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    ~SceneManager();

private:
    SceneManager() = default;
    std::vector<Scene*> mScenes;
};
