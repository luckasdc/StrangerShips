
#include "Ship.h"
#include "Bullet.h"
#include "World.h"

/* generate a random floating point number from min to max */
float randfrom(float min, float max) {
    float range = (max - min);
    float div = RAND_MAX / range;
    return min + (rand() / div);
}

/*
 * SHIP
 */

void Ship::move(Direction dir) {
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
    this->_myWorld = myWorld;
    this->_health =_myWorld->get_level()->get_playerShipHealth();
    this->_speed = _myWorld->get_level()->get_playerShipSpeed();
}

void PlayerShip::shoot() {
    this->_myWorld->addBullet(std::make_shared<Bullet>(false, this->_location));
    this->notify("newBullet");

}

SecondPlayerShip::SecondPlayerShip(World *myWorld) : PlayerShip(myWorld) {
    this->_location.x = -3;
    this->_location.y = -1;
}

/*
 * ENEMY SHIP
 */

EnemyShip::EnemyShip(World* myWorld) {
    this->_location.x = randfrom(4.5, 6.5);
    this->_location.y = randfrom(-3, 3);
    this->_myWorld = myWorld;
    this->_health = _myWorld->get_level()->get_enemyShipHealth();
    this->_speed = _myWorld->get_level()->get_enemyShipSpeed();
}

void EnemyShip::shoot() {
    _shotCounter ++;
    // use the shotcounter to minimalize the amount of shots fired
    if (_shotCounter >= 25 and _location.x <= 4) {
        this->_myWorld->addBullet(std::make_shared<Bullet>(true, this->_location));
        this->notify("newBullet");
        _shotCounter = 0;
    }
}

void EnemyShip::moveRandomDirection() {
    _moveCounter ++;

    if (_location.x <= -4) _outOfRangecounter++;

    if (_moveCounter >= 40) {
        _curdir = Direction(rand() % 10 + 1);
        _moveCounter = 0;
    }

    if (_outOfRangecounter >= 80) {
        _curdir = Direction(Left);
        _moveCounter = 0;
    }
    if (_location.y >= 3) {
        _curdir = Direction(Up);
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

BossShip::BossShip(World *myWorld) : EnemyShip(myWorld) {
    this->_location.x = randfrom(4.5, 6.5);
    this->_location.y = randfrom(-3, 3);
    this->_myWorld = myWorld;
    this->_health = _myWorld->get_level()->get_bossShipHealth();
    this->_speed = _myWorld->get_level()->get_bossShipSpeed();
}

void BossShip::shoot() {
    _shotCounter ++;
    // use the shotcounter to minimalize the amount of shots fired (delay between shots)
    if (_shotCounter >= 10 and _location.x <= 4) {
        this->_myWorld->addBullet(std::make_shared<Bullet>(true, this->_location));
        this->notify("newBullet");
        _shotCounter = 0;
    }
}
