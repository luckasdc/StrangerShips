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
    AIController(std::shared_ptr<World> world) : _world(std::move(world)) {};

    /**
     * @brief decide which actions to do based upon a few (function-based) parameters.
     */
    void makeDecisions();

    bool targetInRange(std::shared_ptr<EnemyShip> enemy);

    bool bulletComingTowardsMe(std::shared_ptr<EnemyShip> enemy);

    void wanderAroundAimlessly(std::shared_ptr<EnemyShip> enemy);

    void fireAtTarget(std::shared_ptr<EnemyShip> enemy);

    void moveAwayFromBullet(std::shared_ptr<EnemyShip> enemy);


private:
    std::shared_ptr<World> _world;

};


#endif //STRANGERSHIPS_AICONTROLLER_H
