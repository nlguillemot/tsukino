#include "menuscene.hpp"

#include <fstream>
#include <sstream>

namespace tsukino
{

MenuScene::MenuScene()
{
    slotAnimData = new AnimData("assets/slot");
}

MenuScene::~MenuScene()
{
    delete slotAnimData;
    for (Animation* a : slotAnims)
    {
        delete a;
    }
}

void MenuScene::init()
{
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

            sf::View dftv = default_view();

            Animation* slot = new Animation(*slotAnimData);
            sf::Vector2f worldpos = v;
            sf::FloatRect rect(slot->anim_rect());
            worldpos.x = worldpos.x * default_view().GetRect().GetWidth() - rect.GetWidth()/2;
            worldpos.y = worldpos.y * default_view().GetRect().GetHeight() - rect.GetHeight()/2;
            slot->set_position(worldpos);
            slotAnims.push_back(slot);
        }
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
