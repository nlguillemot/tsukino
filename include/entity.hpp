#pragma once

#include "animation.hpp"

namespace tsukino
{

class Entity
{
public:
    Entity(const std::string& style);
    virtual ~Entity();

    void reload_entity_data();

    virtual sf::Vector2f position() const;
    virtual void snap_to_position(const sf::Vector2f& position);
    void move(const sf::Vector2f& v);

    virtual sf::FloatRect bounding_box() const;
    virtual sf::FloatRect collision_area() const;

    const Animation& animation() const;
    Animation& animation();

    virtual void update(float dt);
    virtual void draw(sf::RenderTarget& target);

private:
    Animation* animation_;
    AnimData* anim_data_;
    sf::Vector2f position_;
};

}
