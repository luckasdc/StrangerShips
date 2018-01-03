//
// Created by Luckas Declerck on 13/11/17.
//

#include "Ship.h"
#include "Bullet.h"
#include "World.h"

/* generate a random floating point number from min to max */
float randfrom(float min, float max)
{
    float range = (max - min);
    float div = RAND_MAX / range;
    return min + (rand() / div);
}

/*
 * SHIP
 */
// Constructor


// Member Functions

void Ship::move(Direction dir) {

    //TODO: diagonal directions (extra switch-statements?)

    switch (dir) {
        case Up : {
            float newYU {_location.y - _speed};
            if (newYU <= -3) _location.y = -3;
            else _location.y = newYU;
            break;
        }
        case Down : {
            float newYD {_location.y + _speed};
            if (newYD >= +3) _location.y = +3;
            else _location.y = newYD;
            break;
        }
        case Right : {
            float newXR {_location.x + _speed};
            if (newXR >= 4) _location.x = 4;
            else _location.x = newXR;
            break;
        }
        case Left : {
            float newXL {_location.x - _speed};
            if (newXL <= -4) _location.x = -4;
            else _location.x = newXL;
            break;
        }
        case Idle : break;
    }

    this->notify("movement");
}


/*
 * PLAYER SHIP
 */

PlayerShip::PlayerShip(World* myWorld) {
    this->_location.x = -3;
    this->_location.y = 0;
    this->_health = 10;
    this->_speed = 0.09;
    this->_myWorld = myWorld;
}

void PlayerShip::shoot() {

    this->_myWorld->addBullet(std::make_shared<Bullet>(false, this->_location));
    this->notify("newBullet");

}

/*
 * ENEMY SHIP
 */
EnemyShip::EnemyShip(World* myWorld) {
    this->_location.x = 3;
    this->_location.y = randfrom(-3, 3);
    this->_health = 10;
    this->_speed = 0.03;
    this->_myWorld = myWorld;
}

void EnemyShip::shoot() {
    _shotCounter ++;
    // use the shotcounter to minimalize the amount of shots fired
    if (_shotCounter >= 25) {
        this->_myWorld->addBullet(std::make_shared<Bullet>(true, this->_location));
        this->notify("newBullet");
        _shotCounter = 0;
    }

}

void EnemyShip::moveRandomDirection() {
    _moveCounter ++;

    if (_moveCounter >= 50) {
        _curdir = Direction(rand() % 10 + 1);
        _moveCounter = 0;
    }
    move(_curdir);
}

void EnemyShip::escape() {
    Direction newdir = Up;
    if (_location.y < 0 ) newdir = Down;
    _curdir = newdir;
    _moveCounter = 0;
    move(_curdir);

}

