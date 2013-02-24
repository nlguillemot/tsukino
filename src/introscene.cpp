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
 titleAnimData = new AnimData("assets/title_text");
 startAnimData = new AnimData("assets/start");

 backgroundAnim = new Animation(*backgroundAnimData);
 juggaloAnim = new Animation(*juggaloAnimData);
 faceAnim = new Animation(*faceAnimData);
 titleAnim = new Animation(*titleAnimData);
 startAnim = new Animation(*startAnimData);

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
 delete titleAnimData;
 delete titleAnim;
 delete startAnimData;
 delete startAnim;
}

void IntroScene::init()
{
    juggaloAnim->set_alpha(0);
    faceAnim->set_alpha(0);
    titleAnim->set_position(sf::Vector2f(0,-240));
    startAnim->set_position(sf::Vector2f(224,420));
    startAnim->play("idle");
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
    } else if (faceAnim->alpha() < 171) {
        transparencyTween->update(dt);
        faceAnim->set_alpha(transparencyTween->out_value()*171);
        if (faceAnim->alpha() >= 171) {
            transparencyTween->reset();
        }
    } else if (titleAnim->position().y < -60) {
        transparencyTween->update(dt);
        titleAnim->set_position(sf::Vector2f(0, -240 + transparencyTween->out_value()*240 ));
    }


    titleAnim->update(dt);
    backgroundAnim->update(dt);
    juggaloAnim->update(dt);
    faceAnim->update(dt);
    startAnim->update(dt);

}

void IntroScene::draw(sf::RenderTarget& target)
{
    target.Clear();
    backgroundAnim->draw(target);
    juggaloAnim->draw(target);
    faceAnim->draw(target);
    titleAnim->draw(target);
    startAnim->draw(target);
}

void IntroScene::exit()
{
}

}
