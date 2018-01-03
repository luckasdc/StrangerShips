//
// Created by Luckas Declerck on 13/11/17.
//
#include <iostream>
#include "Stopwatch.h"
#include "GameController.h"
#include "KeyController.h"
#include "CollisionController.h"
#include "AIController.h"

Game::Game(uint width, uint height, std::string title)
{
    this->_window = std::make_shared<sf::RenderWindow> (sf::VideoMode(width, height), "Stranger Ships");
    this->_window->create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    // Only one bullet can be shot at a time
    this->_window->setKeyRepeatEnabled(false);

    //TODO change this to add levels
    this->_world = std::make_shared<World> ();
    this->_view = std::make_shared<WorldView> (this->_world, this->_window);

    // We will now initialize the entities in the World model, because this will notify the View to create
    // the corresponding EntityViews.
    this->_world->initialize();
}

void Game::run()
{
    Stopwatch::getStopwatch().start();
    CollisionController cctr (this->_world);
    AIController aictr (this->_world);

    sf::Event event{};

    while (this->_window->isOpen()) {

        // wait 'till the following amount of time has passed to maintain the right FPS
        if (Stopwatch::getStopwatch().elapsedMilliSeconds() < 16) {
            continue;
        }

        Stopwatch::getStopwatch().start();


        // check all the window's events that were triggered since the last iteration of the loop
        while (_window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                _window->close();
            }
            // check if the player is shooting
            if (KeyController::getKeyController().processShooting(event)) _world->getPlayerShip()->shoot();

        }

        // check which keys are currently pressed to control movement
        Direction dir = KeyController::getKeyController().processDirection();
        if(dir != Idle) _world->getPlayerShip()->move(dir);

        // AI-controller: decides what the enemies are going to do
        aictr.makeDecisions();

        // CollisionController: Check if there were any collions and handle them
        cctr.updateBullets();
        cctr.checkPlayerShip();

        // check which entities died during this iteration and remove the according views
        _world->updateEntities();

        // Everything's ready for the next iteration!
        // clear the window with black color
        _window->clear();

        // draw everything again...
        _view->draw();

        // and finally display the current frame!
        _window->display();

    }


}
