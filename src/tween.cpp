#include "tween.hpp"
#include <cmath>

namespace tsukino
{

Tweener::Tweener(TweenFunction fn, float time_to_completion):
fn_(fn)
{
    time_to_completion_ = time_to_completion;
    current_time_ = 0.0f;
}
void Tweener::reset()
{
    current_time_ = 0.0f;
}

void Tweener::update(float dt)
{
    current_time_ += dt;
}

float Tweener::in_value() const
{
    return current_time_ / time_to_completion_;
}

float Tweener::out_value() const
{
    return fn_(in_value());
}

bool Tweener::done() const
{
    return current_time_ >= time_to_completion_;
}

// TWEENS

float tween_linear(float x)
{
    return x;
}

float tween_sqrt(float x)
{
    return std::sqrt(x);
}

float tween_squared(float x)
{
    return x*x;
}

}
