//
// Created by Luckas Declerck on 13/11/17.
//

#ifndef STRANGERSHIPS_SHIP_H
#define STRANGERSHIPS_SHIP_H


#include <tuple>
#include "Entity.h"

enum Direction { Up, Down, Left, Right };

class Ship : public ActiveEntity {

public:

    // Movement
    void move(Direction& dir);

    /**
     * @brief returns double health, if health == 0 --> ship is dead.
     * @return double health,
     */
    double getHealth();
    /**
     * @brief returns the location of an object in [-3, 3] x [-4, 4] dimensions
     * @return a pair of doubles (this->first = x-value; this->second = y-value
     */
    //std::pair<float, float> getLocation();



private:

    //std::pair<float, float> _location;
    float _speed;
    unsigned int _health;





};

class PlayerShip : public Ship {

};

class EnemyShip : public Ship {

};


#endif //STRANGERSHIPS_SHIP_H
