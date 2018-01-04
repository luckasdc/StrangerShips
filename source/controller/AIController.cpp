//
// Created by Luckas Declerck on 2/01/18.
//

#include "AIController.h"
#include "../model/World.h"
#include <iostream>
#include <cmath>
#include <random>

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
    for(auto& bullet : _world->getBulletList()) {
        float difference_vertical = bullet->getLocation().y - enemy->getLocation().y;
        float difference_horizontal = bullet->getLocation().x - enemy->getLocation().x;

        return fabs(difference_vertical) <= 0.2 ;
    }
    return false;
}

void AIController::wanderAroundAimlessly(std::shared_ptr<EnemyShip> enemy) {
    enemy->moveRandomDirection();
}

void AIController::moveAwayFromBullet(std::shared_ptr<EnemyShip> enemy) {

    if (bulletComingTowardsMe(enemy)) {
        enemy->escape();
    }
}

void AIController::fireAtTarget(std::shared_ptr<EnemyShip> enemy) {

    enemy->shoot();
}

void AIController::launchSporadicObstacle(int difficulty) {
    _launches -= difficulty;
    std::random_device rd1;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen1(rd1()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis1(-4, 5);
    _launches -= dis1(gen1) * difficulty;

    if (_launches <= 0) {
         std::random_device rd;  //Will be used to obtain a seed for the random number engine
         std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
         std::uniform_real_distribution<> dis(-2.5, 2.5);
         _world->addSporadicObstacle(0.015 * difficulty, dis(gen));
         _launches = 300;
     }




}

