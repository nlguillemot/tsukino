#pragma once

#include "scene.hpp"

namespace tsukino
{


class IntroScene : public Scene
{
public:
    IntroScene();

    void init();
    void update(float dt);
    void draw(sf::RenderTarget& target);
    void exit();
private:
};

}
