//
// Created by Luckas Declerck on 2/01/18.
//

#ifndef STRANGERSHIPS_AICONTROLLER_H
#define STRANGERSHIPS_AICONTROLLER_H

#include <memory>
#include <utility>
#include "../model/Ship.h"

class World;

class AIController {

public:

    /**
    * @brief constructs a new Controller based upon the given world.
    * @param world
    */
    AIController(std::shared_ptr<World> world) : _world(std::move(world)){};

    /**
     * @brief decide which actions to do based upon a few (function-based) parameters.
     */
    void makeDecisions();

    /**
     * @brief checks if the playership has the same y-values as the enemy
     * @param enemy
     * @return bool
     */
    bool targetInRange(std::shared_ptr<EnemyShip> enemy);

    /**
     * @brief checks if there is a bullet coming towards enemy
     * @param enemy
     * @return bool
     */
    bool bulletComingTowardsMe(std::shared_ptr<EnemyShip> enemy);

    /**
     * @brief if the enemy is not in danger / cannot shoot, it will
     * wander around
     * @param enemy
     */
    void wanderAroundAimlessly(std::shared_ptr<EnemyShip> enemy);

    /**
     * @brief this function will call the shoot() function of the enemy
     * @param enemy
     */
    void fireAtTarget(std::shared_ptr<EnemyShip> enemy);

    /**
     * @brief when this funciton is called, enemy wil escape bullet
     * to the furthest side.
     * @param enemy
     */
    void moveAwayFromBullet(std::shared_ptr<EnemyShip> enemy);

    /**
     * @brief this function controls the launch of sporadic obstacels,
     * based upon the given difficulty level assigned by the level.
     * @param difficulty
     */
    void launchSporadicObstacle();

    /**
     * @brief controls the waves and generates new enemies;
     */
    void controlWaves();

private:
    std::shared_ptr<World> _world;
    int _launches = 200;
    int _wavesToGo = 0;

};


#endif //STRANGERSHIPS_AICONTROLLER_H
