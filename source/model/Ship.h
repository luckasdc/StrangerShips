//
// Created by Luckas Declerck on 13/11/17.
//

#ifndef STRANGERSHIPS_SHIP_H
#define STRANGERSHIPS_SHIP_H


#include <tuple>
#include "Entity.h"


class Ship : public ActiveEntity {

public:

    // Movement
    void move(Direction dir) override ;




private:







};

class PlayerShip : public Ship {

public:
    PlayerShip() {
        this->_location.x = 1;
        this->_location.y = 2;
        this->_health = 10;
        this->_speed = 0.2;
    }


};

class EnemyShip : public Ship {

};


#endif //STRANGERSHIPS_SHIP_H
