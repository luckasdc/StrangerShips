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
class World;
class PlayerShip : public Ship {

public:
    /**
     * @brief default constructor, initializes all the params in ShipView.cpp
     */
    PlayerShip(World* myWorld);

    void shoot();

private:
    World* _myWorld;

};

class World;
class EnemyShip : public Ship {
public:
    /**
     * @brief default constructor, initializes all the params in ShipView.cpp
     */
    EnemyShip(World* myWorld);

    void shoot();

    void moveRandomDirection();

private:
    World* _myWorld;
    int _shotCounter;
    Direction _curdir;
    int _moveCounter;

};


#endif //STRANGERSHIPS_SHIP_H
