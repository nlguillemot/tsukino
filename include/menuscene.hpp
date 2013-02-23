#pragma once

#include "scene.hpp"
#include "animation.hpp"

#include <vector>
#include <map>

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
    AnimData* backgroundAnimData;
    Animation* backgroundAnim;

    std::map<std::string,AnimData*> slotAnimDatas;
    std::vector<Animation*> slotAnims;
};

}
