
#include "Bullet.h"

Bullet::Bullet(bool enemyShot, Location location, float speed) {
    this->_health = 1;
    this->_enemyShot = enemyShot;
    this->_location = location;
    this->_speed = speed;
}

void Bullet::move(Direction dir) {

    switch (dir) {

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
        default: break;

    }

    this->notify("movement");

}

bool Bullet::fromEnemy() {
    return _enemyShot;
}
