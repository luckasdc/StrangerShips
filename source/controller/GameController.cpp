
#include <iostream>
#include <memory>
#include "../firstAid/Singletons.h"
#include "GameController.h"

#include "StateManager.h"


Game::Game(const std::string &configfile) {
    this->_config = std::make_shared<Settings>(configfile);

    this->_preferences = std::make_shared<GamePreferences>(_config->get_width(), _config->get_height());
    _preferences->width = _config->get_width();
    _preferences->height = _config->get_height();
    _preferences->_config = _config;

    this->_preferences->stateManager = std::make_unique<StateManager>();

    // Only one bullet can be shot at a time
    this->_preferences->_window->setKeyRepeatEnabled(false);

    this->_preferences->stateManager->pushState(std::make_unique<MenuState>(this->_preferences));
}

void Game::run() {
    Stopwatch::getInstance().start();

    while (this->_preferences->_window->isOpen()) {

        // wait 'till the following amount of time has passed to maintain the right FPS
        if (Stopwatch::getInstance().elapsedMilliSeconds() < 16) {
            continue;
        }
        Stopwatch::getInstance().start();

        _preferences->stateManager->processStates();
        _preferences->stateManager->getCurrentState()->HandleInput();
        _preferences->stateManager->getCurrentState()->Update();
        _preferences->stateManager->getCurrentState()->Draw();

    }
}

GamePreferences::GamePreferences(int width, int height) {
    _window = std::make_shared<sf::RenderWindow> (sf::VideoMode(width, height), "Flappy Ships");
    _window->create(sf::VideoMode(width, height), "Flappy Ships", sf::Style::Close | sf::Style::Titlebar);

}
