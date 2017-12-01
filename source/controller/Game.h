//
// Created by Luckas Declerck on 13/11/17.
//

#ifndef STRANGERSHIPS_GAME_H
#define STRANGERSHIPS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../view/View.h"
#include <memory>

    class Game {
    public:
        //Constructors
        Game() = default;
        Game(uint width, uint height, std::string title);

        //Methods
        void run ();


    private:
        std::shared_ptr<sf::RenderWindow> _window;
        std::shared_ptr<View> _view;
        std::shared_ptr<World> _world;

        const float dt = 1.0f / 60.0f;



    };


#endif //STRANGERSHIPS_GAME_H
