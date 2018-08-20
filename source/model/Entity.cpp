
#include "Entity.h"

Location ActiveEntity::getLocation() {
    return _location;
}

double ActiveEntity::getHealth() {
    return _health;
}

void ActiveEntity::hit(int health) {
    if (health > (int)this->_health) {this->_health = 0 ; return; }
    this->_health -= health;
}

const Location &PassiveEntity::get_bottomRightCorner() const {
    return _bottomRightCorner;
}

float PassiveEntity::get_width() const {
    return _width;
}

float PassiveEntity::get_height() const {
    return _height;
}

bool PassiveEntity::is_inversed() const {
    return _inversed;
}