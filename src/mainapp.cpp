#include "mainapp.hpp"
#include <SFML/Window/Event.hpp>
#include <cassert>
#include <iostream>

namespace heart
{

MainApp::MainApp(const sf::VideoMode& mode, const std::string& gametitle, Scene* firstscene):
window_(mode,gametitle),
current_scene_(nullptr)
{
    switch_to_scene(firstscene);
}

MainApp::~MainApp()
{
    delete current_scene_;
}

void MainApp::exec()
{
    window_.SetFramerateLimit(60);
    while(window_.IsOpened())
    {
        poll_events();
        update(1000 * window_.GetFrameTime());
        draw();
    }
}

void MainApp::switch_to_scene(Scene* next_scene)
{
    if (current_scene_)
    {
        current_scene_->exit();
        delete current_scene_;
    }

    current_scene_ = next_scene;
    current_scene_->init();

    current_scene_->set_default_view(window_.GetDefaultView());
    current_scene_->set_view(current_scene_->default_view());
}

void MainApp::poll_events()
{
    sf::Event e;
    while(window_.GetEvent(e))
    {
        handle_event(e);
    }   
}

void MainApp::handle_event(const sf::Event& e)
{
    current_scene_->handle_event(e);

    switch(e.Type)
    {
    case sf::Event::Closed:
        window_.Close();
        break;
    default:
        break;
    }
}

void MainApp::update(sf::Uint32 dt)
{
    current_scene_->update(dt);
}

void MainApp::draw()
{
    window_.SetView(current_scene_->view());

    current_scene_->draw(window_);

    window_.Display();
}

}
