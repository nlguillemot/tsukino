#include "fightscene.hpp"
#include "introscene.hpp"

namespace tsukino
{

FightScene::FightScene()
{
    background2AnimData = new AnimData("assets/background2");

    background2Anim = new Animation(*background2AnimData);
}
FightScene::~FightScene()
{
    delete background2AnimData;
    delete background2Anim;
}

void FightScene::init()
{
    p1health = 100;
    p2health = 100;
    p1refresh = 0;
    p2refresh = 0;

    behindBar1 = sf::Shape::Rectangle(sf::Vector2f(8,8),sf::Vector2f(208,32),sf::Color(128,32,32),0.5f,sf::Color(0,0,0));
    behindBar2 = sf::Shape::Rectangle(sf::Vector2f(view().GetRect().GetWidth() - 8,8),sf::Vector2f(view().GetRect().GetWidth() - 208,32),sf::Color(128,32,32),0.5f,sf::Color(0,0,0));
}

void FightScene::update(float dt)
{
    p1bar = sf::Shape::Rectangle(sf::Vector2f(8,8),sf::Vector2f(8 + 2*p1health,32),sf::Color(255,255,51),2.0f,sf::Color(0,0,0));
    p2bar = sf::Shape::Rectangle(sf::Vector2f(view().GetRect().GetWidth() - 8,8),sf::Vector2f(view().GetRect().GetWidth() - 8 - 2*p2health,32),sf::Color(255,255,51),2.0f,sf::Color(0,0,0));

    p1refreshbar = sf::Shape::Rectangle(sf::Vector2f(32,36),sf::Vector2f(32 + 2*p1refresh,48),sf::Color(240,128,128),1.0f,sf::Color(0,0,0));
    p2refreshbar = sf::Shape::Rectangle(sf::Vector2f(view().GetRect().GetWidth() - 32,36),sf::Vector2f(view().GetRect().GetWidth() - 32 - 2*p2refresh,48),sf::Color(240,128,128),1.0f,sf::Color(0,0,0));

    if (p1refresh > 0) {
        p1refresh -= 120 * dt;
        if (p1refresh < 0) {
            p1refresh = 0;
        }
    }
    if (p2refresh > 0) {
        p2refresh -= 120 * dt;
        if (p2refresh < 0) {
            p2refresh = 0;
        }
    }

    if (p1health <= 0 || p2health <= 0) {
        switch_to_next_scene(new IntroScene);
    }

    random_number_engine.seed(std::time(0));
}

void FightScene::handle_event(const sf::Event &e)
{
    if (e.Type == sf::Event::KeyPressed)
    {
        //player1
        //Punch (C)
        if (e.Key.Code == sf::Key::C && p1refresh == 0 && (random_number_engine() % 4 == 2) && p2block == false) {
           p2health -= 8;
           p1refresh += 50;
        }
        //Kick (V)
        if (e.Key.Code == sf::Key::V && p1refresh == 0 && (random_number_engine() % 4 == 2)) {
           p2health -= 16;
           p1refresh += 65;
        }
        //Block (B)
        if (e.Key.Code == sf::Key::B && p1refresh <= 25)
        {
           p1block = true;
        }

        //player2
        //Punch (,)
        if (e.Key.Code == sf::Key::Comma && p2refresh == 0 && (random_number_engine() % 4 == 2) && p1block == false) {
           p1health -= 8;
           p2refresh += 50;
        }
        //Kick (.)
        if (e.Key.Code == sf::Key::Period && p2refresh == 0 && (random_number_engine() % 4 == 2)) {
           p1health -= 16;
           p2refresh += 65;
        }
        //Block (/)
        if (e.Key.Code == sf::Key::Slash && p2refresh <= 25)
        {
           p2block = true;
        }
    }
    if (e.Type == sf::Event::KeyReleased)
    {
        //player1
        //Block (B)
        if (e.Key.Code == sf::Key::B)
        {
            p1block = false;
        }

        //player2
        //Block (/)
        if (e.Key.Code == sf::Key::Slash)
        {
            p2block = false;
        }
    }

}

void FightScene::draw(sf::RenderTarget &target)
{
    target.Clear();
    background2Anim->draw(target);

    target.Draw(behindBar1);
    target.Draw(behindBar2);

    target.Draw(p1bar);
    target.Draw(p2bar);

    target.Draw(p1refreshbar);
    target.Draw(p2refreshbar);


}

}
