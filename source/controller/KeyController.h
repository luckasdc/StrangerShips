//
// Created by Luckas Declerck on 30/12/17.
//

#ifndef STRANGERSHIPS_KEYCONTROLLER_H
#define STRANGERSHIPS_KEYCONTROLLER_H


#include "../model/Entity.h"

class KeyController {

private:
    KeyController() = default;

public:
    // get single instance of Stopwatch
    static KeyController& getKeyController();

    Direction processDirection();
    bool processShooting(sf::Event& event);


};


#endif //STRANGERSHIPS_KEYCONTROLLER_H
