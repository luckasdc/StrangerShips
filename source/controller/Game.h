//
// Created by Luckas Declerck on 13/11/17.
//

#ifndef STRANGERSHIPS_GAME_H
#define STRANGERSHIPS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../view/ShipView.h"
#include <memory>

    class Game {
    public:
        //Constructors
        Game() = default;
        Game(uint width, uint height, std::string title);

        //Methods
        void run ();

        const std::shared_ptr<sf::RenderWindow> &get_window() const;


    private:
        std::shared_ptr<sf::RenderWindow> _window;
        std::shared_ptr<View> _view;
        std::shared_ptr<World> _world;



    };


#endif //STRANGERSHIPS_GAME_H
