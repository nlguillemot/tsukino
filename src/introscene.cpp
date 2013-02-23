#include "introscene.hpp"
#include "menuscene.hpp"

namespace tsukino
{

IntroScene::IntroScene()
{
 backgroundAnimData = new AnimData("assets/background");
 backgroundAnim = new Animation(*backgroundAnimData);
}

IntroScene::~IntroScene()
{
 delete backgroundAnimData;
 delete backgroundAnim;
}

void IntroScene::init()
{
}

void IntroScene::handle_event(const sf::Event &e)
{
    if (e.Type == sf::Event::KeyPressed)
    {
        switch_to_next_scene(new MenuScene());
    }
}

void IntroScene::update(float dt)
{
    backgroundAnim->update(dt);

}

void IntroScene::draw(sf::RenderTarget& target)
{
    target.Clear();
    backgroundAnim->draw(target);
}

void IntroScene::exit()
{
}

}
