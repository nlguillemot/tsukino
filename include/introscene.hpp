#pragma once

#include "scene.hpp"
#include "animation.hpp"
#include "tween.hpp"

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

    Tweener* transparencyTween;


    AnimData* backgroundAnimData;
    AnimData* juggaloAnimData;
    AnimData* faceAnimData;
    AnimData* titleAnimData;
    AnimData* startAnimData;

    Animation* backgroundAnim;
    Animation* juggaloAnim;
    Animation* faceAnim;
    Animation* titleAnim;
    Animation* startAnim;

};

}
