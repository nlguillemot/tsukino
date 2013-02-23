#pragma once

#include "scene.hpp"

namespace tsukino
{

class FightScene : public Scene
{
public:
    FightScene();
    void update(float dt);
    void draw(sf::RenderTarget &target);
};

}
