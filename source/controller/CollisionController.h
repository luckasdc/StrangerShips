//
// Created by Luckas Declerck on 31/11/17.
//

#ifndef STRANGERSHIPS_COLLISIONCONTROLLER_H
#define STRANGERSHIPS_COLLISIONCONTROLLER_H


#include <memory>
#include <utility>

class World;
class Bullet;

class CollisionController {


public:

    /**
     * @brief constructs a new Controller based upon the given world.
     * @param world
     */
    CollisionController(std::shared_ptr<World> world) : _world(std::move(world)) {};

    /**
     * @brief updates all the bullets, which means:
     *  -> it moves the bullet in the right direction
     *  -> it checks collisions by calling the corresponding functions
     */
    void updateBullets();

    /**
     * @brief checks if a bullet collides with an opponent ship, which means:
     *  -> it checks if the bullet hits the ship
     *  -> it will handle the damage with the corresponding ship
     *  -> it will remove the bullet and notify his observers.
     * @param bullet
     */
    void checkBulletWithShips(std::shared_ptr<Bullet> bullet);

/**
     * @brief checks if a bullet collides with an Obstacle, which means:
     *  -> it checks if the bullet hits the obstacle
     *  -> it will handle the damage with the corresponding obstacle
     *  -> it will remove the bullet and notify his observers.
     * @param bullet
     */
    void checkBulletWithObstacles(std::shared_ptr<Bullet> bullet);

    /**
     * @brief checks if a bullet goes out of range:
     *  -> if the y-coordinate of the bullet == 4 or -4, it will remove the bullet
     *     and notify his observers
     * @param bullet
     */
    void checkBulletRange(std::shared_ptr<Bullet> bullet);

    // void checkShipWithObstacles();

private:
    std::shared_ptr<World> _world;

};


#endif //STRANGERSHIPS_COLLISIONCONTROLLER_H
