
#include <iostream>
#include <memory>
#include "../firstAid/Singletons.h"
#include "GameController.h"


// Since there's a lack of make_unique<>() in cpp11.. here it is!
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// Implementation

Game::Game(uint width, uint height, std::string title, bool multiplayer)
{
    this->_preferences = std::make_shared<GamePreferences>();
    this->_preferences->_window = std::make_shared<sf::RenderWindow> (sf::VideoMode(_preferences->width, _preferences->height), "Flappy Ships");
    this->_preferences->_window->create(sf::VideoMode(_preferences->width, _preferences->height), "Flappy Ships", sf::Style::Close | sf::Style::Titlebar);
    // Only one bullet can be shot at a time
    this->_preferences->_window->setKeyRepeatEnabled(false);

    this->_preferences->stateManager.pushState(make_unique<PlayingState>(_preferences));
}

void Game::run()
{
    Stopwatch::getInstance().start();

    sf::Event event{};

    while (this->_preferences->_window->isOpen()) {

        // wait 'till the following amount of time has passed to maintain the right FPS
        if (Stopwatch::getInstance().elapsedMilliSeconds() < 16) {
            continue;
        }

        Stopwatch::getInstance ().start();

        _preferences->stateManager.processStates();
        _preferences->stateManager.getCurrentState()->HandleInput();
        _preferences->stateManager.getCurrentState()->Update();
        _preferences->stateManager.getCurrentState()->Draw();

    }
    
}

