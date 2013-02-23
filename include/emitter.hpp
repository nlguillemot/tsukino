#pragma once

#include "effect.hpp"

#include <vector>

namespace tsukino
{

class Emitter
{
public:
    Emitter(float spawn_rate);
    virtual ~Emitter();

    void update(float dt);
    void draw(sf::RenderTarget& target);

    virtual Effect* spawn() = 0;
private:
    float spawn_rate_;
    float accumulated_time_;

    std::vector<Effect*> instances_;
};

}
