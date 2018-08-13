

#include <SFML/Window/Event.hpp>
#include "KeyController.h"

KeyController &KeyController::getKeyController() {
    // lazy initialization
    static auto *instance = new KeyController();
    return *instance;}

Direction KeyController::processDirection(bool multiplayer) {

    // TODO Multiplayer implementation here
    /*
     *  ptr<Ship> in arguments?
     */
    if (multiplayer) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) return Left;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) return Right;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) return Up;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) return Down;

        return Idle;

    };

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return Left;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return Right;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) return Up;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) return Down;

    else return Idle;

}

bool KeyController::processShooting(sf::Event &event, bool multiplayer) {

    if(multiplayer) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::LShift) {
                return true;
            }
        }
        return false;
    }


    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            return true;
        }
    }
    return false;
}

bool KeyController::IsSpriteClicked(std::shared_ptr<sf::Sprite> object, sf::Mouse::Button button, std::shared_ptr<sf::RenderWindow> window) {
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect playButtonRect(static_cast<int>(object->getPosition().x),
                                   static_cast<int>(object->getPosition().y),
                                   static_cast<int>(object->getGlobalBounds().width),
                                   static_cast<int>(object->getGlobalBounds().height));

        if (playButtonRect.contains(sf::Mouse::getPosition(*window)))
        {
            return true;
        }
    }

    return false;
}

