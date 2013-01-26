#pragma once
#include <SFML/Graphics.hpp>

namespace heart
{

class MainApp;

class Scene
{
public:
    virtual ~Scene(){}

    virtual void handle_event(const sf::Event& e){}

    virtual void init(){}
    virtual void update(sf::Uint32 dt){}
    virtual void exit(){}

    virtual void draw(sf::RenderTarget& target){}
};

}
