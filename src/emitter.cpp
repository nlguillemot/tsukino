#include "emitter.hpp"

namespace tsukino
{

Emitter::Emitter(float spawn_rate)
{
    spawn_rate_ = spawn_rate;
    accumulated_time_ = 0;
}

Emitter::~Emitter()
{
    for (Effect* e : instances_)
    {
        delete e;
    }
}

void Emitter::update(float dt)
{
    accumulated_time_ += dt;
    while (accumulated_time_ >= spawn_rate_)
    {
        accumulated_time_ -= spawn_rate_;
        instances_.push_back(spawn());
    }

    size_t number = instances_.size();
    for (size_t i = 0; i < number; i++)
    {
        instances_[i]->update(dt);
        if (instances_[i]->done())
        {
            delete instances_[i];
            std::swap(instances_[i],instances_[number-1]);
            number--;
        }
    }

    instances_.erase(instances_.begin() + number,instances_.end());
}

void Emitter::draw(sf::RenderTarget &target)
{
    for (Effect* e : instances_)
    {
        e->draw(target);
    }
}

}
