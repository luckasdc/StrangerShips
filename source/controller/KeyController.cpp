//
// Created by Luckas Declerck on 30/12/17.
//

#include <SFML/Window/Event.hpp>
#include "KeyController.h"

KeyController &KeyController::getKeyController() {
    // lazy initialization
    static auto *instance = new KeyController();
    return *instance;}

Direction KeyController::processDirection() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return Left;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) return Left;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return Right;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) return Right;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) return Up;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) return Up;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) return Down;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) return Down;
    else return Idle;

}


