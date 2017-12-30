//
// Created by Luckas Declerck on 13/11/17.
//
#include <iostream>
#include "Stopwatch.h"
#include "GameController.h"
#include "KeyController.h"

Game::Game(uint width, uint height, std::string title)
{
    this->_window = std::make_shared<sf::RenderWindow> (sf::VideoMode(width, height), "Stranger Ships");
    this->_window->create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

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
    sf::Event event;



    while (this->_window->isOpen()) {

        // while Stopwatch::remainingUntilRefresh > 0:




            if (Stopwatch::getStopwatch().elapsedMilliSeconds() < 16) {
                //std::cout << &Stopwatch::getStopwatch() << std::endl;
                //std::cout << Stopwatch::getStopwatch().elapsedMilliSeconds() << std::endl;
                continue;
            }

            Stopwatch::getStopwatch().start();

            Direction dir = KeyController::getKeyController().processDirection();
            _world->getPlayerShip()->move(dir);
            // check all the window's events that were triggered since the last iteration of the loop
            while (_window->pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed) {
                    _window->close();

                }

            }

            // clear the window with black color
            _window->clear(sf::Color::Black);

            // draw everything here...
            _view->draw();


            // end the current frame
            _window->display();




    }


}
