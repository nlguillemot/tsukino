#pragma once

#include "scene.hpp"
#include "animation.hpp"

namespace tsukino
{

class FightScene : public Scene
{
public:
    FightScene();
    ~FightScene();
    void init();
    void update(float dt);
    void handle_event(const sf::Event &e);
    void draw(sf::RenderTarget &target);

private:
    AnimData* background2AnimData;

    Animation* background2Anim;

    int p1health;
    int p2health;
    float p1refresh;
    float p2refresh;

    bool p1block;
    bool p2block;

    sf::Shape p1bar;
    sf::Shape p2bar;
    sf::Shape p1refreshbar;
    sf::Shape p2refreshbar;

    sf::Shape behindBar1;
    sf::Shape behindBar2;

    std::mt19937 random_number_engine;


};

}
