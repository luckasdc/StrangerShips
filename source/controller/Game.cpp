//
// Created by Luckas Declerck on 13/11/17.
//
#include <iostream>
#include "Game.h"
Game::Game(uint width, uint height, std::string title)
{
    this->window_ = std::make_shared<sf::RenderWindow> (sf::VideoMode(width, height), "Stranger Ships");
    this->window_->create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
}

void Game::run()
{

    while (this->window_->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event {};
        while (window_->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window_->close();
        }

        // clear the window with black color
        window_->clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window_->display();



    }


}


