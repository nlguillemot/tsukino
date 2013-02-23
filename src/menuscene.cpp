#include "menuscene.hpp"
#include "explosion.hpp"
#include "fader.hpp"

#include <fstream>
#include <sstream>
#include <random>
#include <iostream>

namespace tsukino
{

template<class RandomEngine>
class RandomEmitter : public Emitter
{
public:
    RandomEmitter(sf::FloatRect bounds, const Animation& anim):
        Emitter(0.3f),
        anim_(anim)
    {
        bounds_ = bounds;
        randomizer_.seed(time(0));
    }

    Effect* spawn()
    {
        sf::Vector2f random_pos(
                    bounds_.Left + randomizer_() / (float)randomizer_.max() * bounds_.GetWidth(),
                    bounds_.Top + randomizer_() / (float)randomizer_.max() * bounds_.GetHeight());

        // return new Explosion(anim_,random_pos,300.0f,200.0f,tween_sqrt);
        return new Fader(anim_,true,random_pos,1.0f,tween_squared);

    }
private:
    sf::FloatRect bounds_;
    const Animation& anim_;
    RandomEngine randomizer_;
};

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

    delete juggaloFaceAnimData1;
    delete juggaloFaceAnimData2;
    delete juggaloFaceAnim1;
    delete juggaloFaceAnim2;
    delete juggalo_emitter_;
    delete juggalo_emitter2_;
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


    juggaloFaceAnimData1 = new AnimData("assets/jughead1");
    juggaloFaceAnimData2 = new AnimData("assets/jughead2");
    juggaloFaceAnim1 = new Animation(*juggaloFaceAnimData1);
    juggaloFaceAnim2 = new Animation(*juggaloFaceAnimData2);

    juggalo_emitter_ = new RandomEmitter<std:: minstd_rand>(default_view().GetRect(),*juggaloFaceAnim1);
    juggalo_emitter2_ = new RandomEmitter<std::mt19937>(default_view().GetRect(),*juggaloFaceAnim2);

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

    juggalo_emitter_->update(dt);
    juggalo_emitter2_->update(dt);
}

void MenuScene::draw(sf::RenderTarget &target)
{
    target.Clear();

    backgroundAnim->draw(target);

    juggalo_emitter_->draw(target);
    juggalo_emitter2_->draw(target);

    for (Animation* a : slotAnims)
    {
        a->draw(target);
    }
}

}
