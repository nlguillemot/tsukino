#pragma once

#include "scene.hpp"
#include "animation.hpp"

namespace tsukino
{

class LoadingScene : public Scene
{
public:
    LoadingScene(Scene* s);
    ~LoadingScene();

    void init();
    void update(float dt);
    void handle_event(const sf::Event &e);
    void draw(sf::RenderTarget &target);
private:
    Scene* sceneAfterLoading;

    std::vector<std::string> tipList;
    unsigned int currentTip;

    AnimData* loadingAnimData;
    Animation* loadingAnim;

    AnimData* keyPromptAnimData;
    Animation* keyPromptAnim;

    sf::String loadingText;
    sf::String loadingTips;

    float loadTimer;

    std::mt19937 random_number_engine;

};

}
