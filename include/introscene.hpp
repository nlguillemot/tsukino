#pragma once

#include "scene.hpp"
#include "animation.hpp"

namespace tsukino
{


class IntroScene : public Scene
{
public:
    IntroScene();
    ~IntroScene();

    void handle_event(const sf::Event &e);
    void init();
    void update(float dt);
    void draw(sf::RenderTarget& target);
    void exit();
private:
    AnimData* backgroundAnimData;
    Animation* backgroundAnim;
};

}
