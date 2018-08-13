
#ifndef STRANGERSHIPS_KEYCONTROLLER_H
#define STRANGERSHIPS_KEYCONTROLLER_H


#include "SFML/Graphics.hpp"
#include "../model/Entity.h"

class KeyController {


public:

    KeyController() = default;
    ~KeyController() = default;

    /**
     * @brief get single instance of Stopwatch
     * @return instance
     */
    static KeyController& getKeyController();

    /**
     * @brief returns the right direction based on the currently pressed buttons
     * @return enum Direction
     */
    Direction processDirection(bool multiplayer);

    /**
     * @brief returns true if space bar is pressed
     * @param event
     * @return boolean
     */
    bool processShooting(sf::Event& event, bool multiplayer);

    /**
     * @brief returns if a given sprite has been clicked
     * @param  sf::Sprite, sf::Mouse::Button, sf::RenderWindow
     * @return boolean
     */
    bool IsSpriteClicked(std::shared_ptr<sf::Sprite> object, sf::Mouse::Button button, std::shared_ptr<sf::RenderWindow> window);

};


#endif //STRANGERSHIPS_KEYCONTROLLER_H
