
#ifndef STRANGERSHIPS_KEYCONTROLLER_H
#define STRANGERSHIPS_KEYCONTROLLER_H


#include "../model/Entity.h"

class KeyController {

private:
    KeyController() = default;

public:

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


};


#endif //STRANGERSHIPS_KEYCONTROLLER_H
