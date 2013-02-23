#pragma once

#include "scene.hpp"
#include "animation.hpp"

#include <vector>

namespace tsukino
{

class MenuScene : public Scene
{
public:
    MenuScene();
    ~MenuScene();

    void init();
    void handle_event(const sf::Event &e);
    void update(float dt);
    void draw(sf::RenderTarget &target);
private:
    AnimData* slotAnimData;
    std::vector<Animation*> slotAnims;
};

}
