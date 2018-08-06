

#include <SFML/Window/Event.hpp>
#include "KeyController.h"

KeyController &KeyController::getKeyController() {
    // lazy initialization
    static auto *instance = new KeyController();
    return *instance;}

Direction KeyController::processDirection() {

    // TODO Multiplayer implementation here
    /*
     *  ptr<Ship> in arguments?
     */

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

bool KeyController::processShooting(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            return true;
        }
    }
    return false;
}

