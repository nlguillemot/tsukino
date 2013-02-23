#include "menuscene.hpp"

#include <fstream>
#include <sstream>

namespace tsukino
{

MenuScene::MenuScene()
{
    backgroundAnimData = new AnimData("assets/selectionbackground");
    backgroundAnim = new Animation(*backgroundAnimData);
}

MenuScene::~MenuScene()
{
    delete backgroundAnimData;
    delete backgroundAnim;

    for (auto& kv : slotAnimDatas)
    {
        delete kv.second;
    }

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
            std::string animname;
            ss >> v.x;
            ss >> v.y;
            ss >> animname;

            if (slotAnimDatas.find(animname) == slotAnimDatas.end())
            {
                slotAnimDatas[animname] = new AnimData("assets/" + animname);
            }

            Animation* slot = new Animation(*slotAnimDatas[animname]);
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

    backgroundAnim->draw(target);

    for (Animation* a : slotAnims)
    {
        a->draw(target);
    }
}

}
