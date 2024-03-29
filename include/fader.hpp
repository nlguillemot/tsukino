#pragma once

#include "effect.hpp"
#include "tween.hpp"

namespace tsukino
{

class Fader : public Effect
{
public:
    Fader(const Animation& anim, bool fadeout, const sf::Vector2f& position, float time, TweenFunction tween);
    
    void update(float dt);
    void draw(sf::RenderTarget& target);
    bool done() const;
private:
    bool fadeout_;
    Tweener tweener_;
};

}
