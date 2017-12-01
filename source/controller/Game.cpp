//
// Created by Luckas Declerck on 13/11/17.
//
#include <iostream>
#include "Stopwatch.h"
#include "Game.h"

Game::Game(uint width, uint height, std::string title)
{
    this->_window = std::make_shared<sf::RenderWindow> (sf::VideoMode(width, height), "Stranger Ships");
    this->_window->create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
}

void Game::run()
{

    Stopwatch::getStopwatch().start();

    while (this->_window->isOpen())
    {

        // while Stopwatch::remainingUntilRefresh > 0:


            if (Stopwatch::getStopwatch().elapsedMilliSeconds() < 16) {
                //std::cout << &Stopwatch::getStopwatch() << std::endl;
                //std::cout << Stopwatch::getStopwatch().elapsedMilliSeconds() << std::endl;
                continue;
            }
            Stopwatch::getStopwatch().start();



            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event {};
            while (_window->pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    _window->close();
            }

            // clear the window with black color
            _window->clear(sf::Color::Black);

            // draw everything here...
            // window.draw(...);

            // end the current frame
            _window->display();



    }


}


