#include "introscene.hpp"

namespace tsukino
{

IntroScene::IntroScene()
{
 backgroundAnimData = new AnimData("assets/bird");
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

void IntroScene::update(float dt)
{
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
