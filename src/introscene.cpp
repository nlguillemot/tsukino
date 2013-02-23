#include "introscene.hpp"
#include "menuscene.hpp"

namespace tsukino
{

IntroScene::IntroScene()
{
 transparencyTween = new Tweener(tween_sqrt,1);

 backgroundAnimData = new AnimData("assets/title_backdrop");
 juggaloAnimData = new AnimData("assets/title_juggalos");
 faceAnimData = new AnimData("assets/title_faces");

 backgroundAnim = new Animation(*backgroundAnimData);
 juggaloAnim = new Animation(*juggaloAnimData);
 faceAnim = new Animation(*faceAnimData);
}

IntroScene::~IntroScene()
{
 delete backgroundAnimData;
 delete backgroundAnim;
 delete juggaloAnimData;
 delete juggaloAnim;
 delete faceAnimData;
 delete faceAnim;
 delete transparencyTween;
}

void IntroScene::init()
{
    juggaloAnim->set_alpha(0);
    faceAnim->set_alpha(0);
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
    if (juggaloAnim->alpha() < 133) {
        transparencyTween->update(dt);
        juggaloAnim->set_alpha(transparencyTween->out_value()*133);
        if (juggaloAnim->alpha() >= 133) {
            transparencyTween->reset();

        }
    } else {
        transparencyTween->update(dt);
        faceAnim->set_alpha(transparencyTween->out_value()*171);
    }

    backgroundAnim->update(dt);
    juggaloAnim->update(dt);
    faceAnim->update(dt);

}

void IntroScene::draw(sf::RenderTarget& target)
{
    target.Clear();
    backgroundAnim->draw(target);
    juggaloAnim->draw(target);
    faceAnim->draw(target);
}

void IntroScene::exit()
{
}

}
