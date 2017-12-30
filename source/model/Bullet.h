//
// Created by Luckas Declerck on 13/11/17.
//

#ifndef STRANGERSHIPS_BULLET_H
#define STRANGERSHIPS_BULLET_H


#include "Entity.h"

class Bullet : public ActiveEntity {
    /**
         * @brief Constructs a bullet with a starting position. It takes the
         * x-coordinate from its firing ship and shoots in the right direction.
         *
         *
         *
         * @param    enemyShot  true if enemy fired, false if player fired
         * @param    location        current position of the firing ship
         * @param    speed      the speed with which the bullet moves each step:
         *                      default = 0.1
         */
    Bullet( bool enemyShot,  Location location, float speed = 0.1) : ActiveEntity(location, speed, 10), _enemyShot(enemyShot)

    void move(Direction dir) override;

private:
    bool _enemyShot;

};


#endif //STRANGERSHIPS_BULLET_H
