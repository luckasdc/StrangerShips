//
// Created by Luckas Declerck on 13/11/17.
//

#include "Entity.h"

Location ActiveEntity::getLocation() {
    return _location;
}

/// Getters

double ActiveEntity::getHealth() {
    return _health;
}


void ActiveEntity::hit(int health) {
    this->_health -= health;
}

