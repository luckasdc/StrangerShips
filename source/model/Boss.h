//
// Created by Luckas Declerck on 22/07/18.
//

#ifndef STRANGERSHIPS_BOSS_H
#define STRANGERSHIPS_BOSS_H

class World;

#include "Ship.h"


class Boss : public EnemyShip {

public:
    /**
     * @brief default constructor, initializes all the params in BossView.cpp
     * using the given WorldPointer.
     */
    Boss(World* myWorld);

private:
    World* _myWorld;
    int _shotCounter;
    Direction _curdir;
    int _moveCounter;
    int _outOfRangecounter = 0;


};


#endif //STRANGERSHIPS_BOSS_H
