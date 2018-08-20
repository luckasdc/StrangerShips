
#ifndef STRANGERSHIPS_BULLET_H
#define STRANGERSHIPS_BULLET_H

#include "Entity.h"

class Bullet : public ActiveEntity {

public:
    /**
         * @brief Constructs a bullet with a starting position. It takes the
         * x-coordinate from its firing ship and shoots in the right direction.
         *
         * @param    enemyShot  true if enemy fired, false if player fired
         * @param    location        current position of the firing ship
         * @param    speed      the speed with which the bullet moves each step:
         *                      default = 0.1
         */
    Bullet(bool enemyShot, Location location, float speed = 0.1);

    /**
     * @brief overrides the virtual move function of ActiveEntity and controls the bullet movement.
     * Bullet can only move left or right, based on friendly or non-friendly fire.
     * @param dir
     */
    void move(Direction dir) override;

    /**
     * @brief returns boolean if bullet is from enemy or not (== getter _enemyShot)
     * @return bool
     */
    bool fromEnemy();

private:
    bool _enemyShot;

};


#endif //STRANGERSHIPS_BULLET_H
