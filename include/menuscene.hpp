#pragma once

#include "scene.hpp"

namespace tsukino
{

class MenuScene : public Scene
{
public:
    MenuScene();
    ~MenuScene();

    void handle_event(const sf::Event &e);
    void update(float dt);
    void draw(sf::RenderTarget &target);
private:
};

}
