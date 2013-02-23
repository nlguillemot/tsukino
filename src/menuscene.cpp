#include "menuscene.hpp"

#include <fstream>
#include <sstream>

namespace tsukino
{

MenuScene::MenuScene()
{
    slotAnimData = new AnimData("assets/slot");

    std::ifstream ifs("menu/mainmenu.menu");
    std::string line;

    while (std::getline(ifs,line))
    {
        if (line.substr(0,4) == "slot")
        {
            std::stringstream ss;
            ss << line.substr(4);

            sf::Vector2f v;
            ss >> v.x;
            ss >> v.y;

            Animation* slot = new Animation(*slotAnimData);
            slot->set_position(v);
            slotAnims.push_back(slot);
        }
    }
}

MenuScene::~MenuScene()
{
    delete slotAnimData;
    for (Animation* a : slotAnims)
    {
        delete a;
    }
}

void MenuScene::handle_event(const sf::Event &e)
{

}

void MenuScene::update(float dt)
{
    for (Animation* a : slotAnims)
    {
        a->update(dt);
    }
}

void MenuScene::draw(sf::RenderTarget &target)
{
    target.Clear();

    for (Animation* a : slotAnims)
    {
        a->draw(target);
    }
}

}
