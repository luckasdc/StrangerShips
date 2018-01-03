
#ifndef STRANGERSHIPS_COLLISIONCONTROLLER_H
#define STRANGERSHIPS_COLLISIONCONTROLLER_H


#include <memory>
#include <utility>
#include "../model/Entity.h"

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
    * @brief checks if the playership has hit an obstacle:
    *  -> it checks if the shit hits the obstacle
    *  -> it will handle the damage with the playership
    */
    void checkPlayerShip();

    /**
    * @brief checks if a bullet collides with an opponent ship, which means:
    *  -> it checks if the bullet hits the ship
    *  -> it will handle the damage with the corresponding ship
    *  -> it will remove the bullet and notify his observers.
    * @param bullet
    */
    void checkBulletWithShips(std::shared_ptr<Bullet> bullet);

    /**
    * @brief checks if a bullet goes out of range:
    *  -> if the y-coordinate of the bullet == 4 or -4, it will remove the bullet
    *     and notify his observers
    * @param bullet
    */
    void checkBulletRange(std::shared_ptr<Bullet> bullet);

    /**
    * @brief checks collision by taking two Locations and generating circles to check if they intersect
    * @param location 1, location 2
    */
    bool circleCollisionTest(Location first, Location second);

    /**
     * @brief checks the collision between a point (circle) and a rectangle. The equation is
     * actually very simple! (cfr. https://yal.cc/rectangle-circle-intersection-test/)
     * @param circle
     * @param rectangle
     * @param width
     * @param height
     * @param inversed
     * @return
     */
    bool circleRectangleCollisionTest(Location circle, Location rectangle, float width, float height, bool inversed);

private:
    std::shared_ptr<World> _world;
    int waitCounter = 0;

};


#endif //STRANGERSHIPS_COLLISIONCONTROLLER_H
