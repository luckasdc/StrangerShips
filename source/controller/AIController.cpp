//
// Created by Luckas Declerck on 2/01/18.
//

#include "AIController.h"
#include "../model/World.h"
#include <iostream>
#include <cmath>

void AIController::makeDecisions() {

    for (auto& enemy : _world->getEnemyShipList()) {

        if( targetInRange(enemy))
        {
            fireAtTarget(enemy);
        }
        else if( bulletComingTowardsMe(enemy))
        {
            moveAwayFromBullet(enemy);
        }
        else
        {
            wanderAroundAimlessly(enemy);
        }

    }

}

bool AIController::targetInRange(std::shared_ptr<EnemyShip> enemy) {
    float difference = _world->getPlayerShip()->getLocation().y - enemy->getLocation().y;
    return fabs(difference) <= 0.2;
}

bool AIController::bulletComingTowardsMe(std::shared_ptr<EnemyShip> enemy) {
    return false;
}

void AIController::wanderAroundAimlessly(std::shared_ptr<EnemyShip> enemy) {
    enemy->moveRandomDirection();
}

void AIController::moveAwayFromBullet(std::shared_ptr<EnemyShip> enemy) {

}

void AIController::fireAtTarget(std::shared_ptr<EnemyShip> enemy) {

    enemy->shoot();
}
