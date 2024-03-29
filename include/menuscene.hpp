#pragma once

#include "scene.hpp"
#include "animation.hpp"
#include "emitter.hpp"
#include "tween.hpp"
#include <SFML/Graphics.hpp>


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
    std::vector<std::string> slotNames;

    AnimData* juggaloFaceAnimData1;
    Animation* juggaloFaceAnim1;
    AnimData* juggaloFaceAnimData2;
    Animation* juggaloFaceAnim2;

    Emitter* juggalo_emitter_;
    Emitter* juggalo_emitter2_;

    AnimData* selectorAnimData;
    Animation* p1selectorAnim;
    Animation* p2selectorAnim;

    Tweener* scrollingTextTween;

    sf::String scrollingText;
    sf::String p1name;
    sf::String p2name;
    sf::String enterToPlay;

    unsigned int p1selectorIndex;
    unsigned int p2selectorIndex;
};

}
