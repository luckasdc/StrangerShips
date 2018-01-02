//
// Created by Luckas Declerck on 31/11/17.
//

#include <iostream>
#include <cmath>
#include "CollisionController.h"
#include "../model/World.h"

void CollisionController::updateBullets() {

    // creating a copy of BulletList to avoid referencing nullptrs due to deletes
    auto snapshotOfBullets = _world->getBulletList();

    for (auto& bullet : snapshotOfBullets) {

        Direction dir = Right;
        if(bullet->fromEnemy()) dir = Left;

        bullet->move(dir);

        // check bullet collision with PlayerShip
        checkBulletWithShips(bullet);

        // check bullet collision with obstacle
        //checkBulletWithObstacles(bullet);

        // check if bullet runs out of range
        checkBulletRange(bullet);

        }


    }

void CollisionController::checkBulletWithShips(std::shared_ptr<Bullet> bullet) {


    for (auto enemy : _world->getEnemyShipList()) {

        if (bullet->fromEnemy()) break;

        if (doTheyCollide(enemy->getLocation(), bullet->getLocation())) {
            //std::cout << "COLLISION" << std::endl;
            bullet->hit(1);
            enemy->hit(3);
            //_world->removeBullet(bullet);

        }
    }

}

void CollisionController::checkBulletWithObstacles(std::shared_ptr<Bullet> bullet) {

}

void CollisionController::checkBulletRange(std::shared_ptr<Bullet> bullet) {

    if (bullet->getLocation().x == 4 or bullet->getLocation().x == -4) {
        bullet->hit(1);
        //_world->removeBullet(bullet);
    }

}

bool CollisionController::doTheyCollide(Location first, Location second) {

    float radius_circle1 = 0.15;
    float radius_circle2 = 0.15;

    float dx = first.x - second.x;
    float dy = first.y - second.y;
    float distance = std::sqrt(dx * dx + dy * dy);

    return distance < radius_circle1 + radius_circle2;
}
