#include "loadingscene.hpp"
#include <random>
#include <fstream>

namespace tsukino
{

LoadingScene::LoadingScene(Scene* nextScene)
{
    sceneAfterLoading = nextScene;
    loadingAnimData = new AnimData("assets/loading");
    loadingAnim = new Animation(*loadingAnimData);
    loadingAnim->set_origin(loadingAnim->point("origin"));

    keyPromptAnimData = new AnimData("assets/start");
    keyPromptAnim = new Animation(*keyPromptAnimData);
    keyPromptAnim->set_origin(keyPromptAnim->point("origin"));
}

LoadingScene::~LoadingScene()
{
    delete loadingAnimData;
    delete loadingAnim;
    delete keyPromptAnimData;
    delete keyPromptAnim;
}

void LoadingScene::init()
{
    loadTimer = 0;
    loadingText.SetText("LOADING");
    loadingText.SetColor(sf::Color(226,10,22));
    loadingText.SetPosition(32, view().GetRect().GetHeight() - 32 - loadingText.GetRect().GetHeight());
    loadingAnim->set_position(sf::Vector2f(view().GetRect().GetWidth() *3/4,view().GetRect().GetHeight()*3/4));
    keyPromptAnim->set_position(sf::Vector2f(view().GetRect().GetWidth()/2 - keyPromptAnim->transformed_width()/2, 64));
    keyPromptAnim->play("idle");

    std::ifstream ifs("assets/pro.tips");
    std::string line;
    while(std::getline(ifs,line))
    {
        tipList.push_back("Pro-Tip: " + line);
    }

    random_number_engine.seed(std::time(0));
    currentTip = random_number_engine() % tipList.size();
    loadingTips.SetText(tipList[currentTip]);

    loadingTips.SetColor(sf::Color(200,10,22));
    loadingTips.SetSize(18);

}

void LoadingScene::update(float dt)
{

    if (loadTimer < 3 && loadTimer + dt >= 3)
    {
        loadingTips.SetText(tipList[random_number_engine() % tipList.size()]);
    }

    loadingTips.SetPosition(sf::Vector2f(view().GetRect().GetWidth()/2 - loadingTips.GetRect().GetWidth()/2, 128));
    loadingAnim->rotate(-dt * 180);
    loadingAnim->update(dt);
    keyPromptAnim->update(dt);
    loadTimer += dt;
}

void LoadingScene::handle_event(const sf::Event &e)
{
    if (e.Type == sf::Event::KeyPressed && loadTimer >= 6)
    {
        switch_to_next_scene(sceneAfterLoading);
    }
}

void LoadingScene::draw(sf::RenderTarget &target)
{
    target.Clear();

    target.Draw(loadingText);
    target.Draw(loadingTips);
    loadingAnim->draw(target);
    if (loadTimer >= 6)
    {
        keyPromptAnim->draw(target);
    }
}

}
