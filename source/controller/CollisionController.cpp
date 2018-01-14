
#include <iostream>
#include <cmath>
#include "CollisionController.h"
#include "../model/World.h"

void CollisionController::updateBulletsAndObstacles() {

    // creating a copy of BulletList to avoid referencing nullptrs due to deletes
    auto snapshotOfBullets = _world->getBulletList();
    auto snapshotOfObstacles = _world->getObstacleList();

    for (auto &bullet : snapshotOfBullets) {

        Direction dir = Right;
        if (bullet->fromEnemy()) dir = Left;

        bullet->move(dir);

        // check bullet collision with PlayerShip
        checkBulletWithShips(bullet);

        // check if bullet runs out of range
        checkBulletRange(bullet);

    }


    for (auto &obstacle : snapshotOfObstacles) {
        checkObstacleRange(obstacle);
    }
}



void CollisionController::checkPlayerShip() {

    waitCounter++;
    auto snapshotOfObstacles = _world->getObstacleList();

    for (auto& obstacle : snapshotOfObstacles) {
        if (waitCounter >= 60 and circleRectangleCollisionTest(_world->getPlayerShip()->getLocation(),
                                     obstacle->get_bottomRightCorner(),
                                     obstacle->get_width(),
                                     obstacle->get_height(),
                                     obstacle->is_inversed()))

        {
            _world->getPlayerShip()->hit(2);
            std::cout << "YOU DUMBASS" << std::endl; // TODO GET THIS AWAY
            waitCounter = 0;
        };
    }
}

void CollisionController::checkBulletWithShips(std::shared_ptr<Bullet> bullet) {

    if (circleCollisionTest(bullet->getLocation(), _world->getPlayerShip()->getLocation()) and bullet->fromEnemy()) {
        bullet->hit(1);
        _world->getPlayerShip()->hit(1);
    }

    for (auto enemy : _world->getEnemyShipList()) {

        if (bullet->fromEnemy()) break;

        if (circleCollisionTest(enemy->getLocation(), bullet->getLocation())) {
            //std::cout << "COLLISION" << std::endl;
            bullet->hit(1);
            enemy->hit(3);

        }
    }

}


void CollisionController::checkBulletRange(std::shared_ptr<Bullet> bullet) {

    if (bullet->getLocation().x == 4 or bullet->getLocation().x == -4) {
        bullet->hit(1);
        //_world->removeBullet(bullet);
    }
}

void CollisionController::checkObstacleRange(std::shared_ptr<Obstacle> obstacle) {
    if (obstacle->get_bottomRightCorner().x + obstacle->get_width() < -4) {
        _world->removeObstacle(obstacle);
        std::cout << "Obstacle Out Of Range!" << std::endl;
    }
}

bool CollisionController::circleCollisionTest(Location first, Location second) {

    float radius_circle1 = 0.15;
    float radius_circle2 = 0.15;

    float dx = first.x - second.x;
    float dy = first.y - second.y;
    float distance = std::sqrt(dx * dx + dy * dy);

    return distance < radius_circle1 + radius_circle2;
}

bool CollisionController::circleRectangleCollisionTest(Location circle, Location rectangle, float width, float height, bool inversed) {

    float radius_circle = 0.2;
    //std::cout << circle.x << ", " << circle.y << std::endl;

    if (inversed) {

        if (rectangle.y >= 0) {
            float dx = circle.x - std::max(rectangle.x , std::min(circle.x, rectangle.x + width ));
            float dy = circle.y - std::max(rectangle.y - height, std::min(circle.y, rectangle.y + height - height  ));
            return (dx * dx + dy * dy) < (radius_circle * radius_circle);
        }

        float dx = circle.x - std::max(rectangle.x , std::min(circle.x, rectangle.x + width ));
        float dy = circle.y - std::max(rectangle.y, std::min(circle.y, rectangle.y + height));
        return (dx * dx + dy * dy) < (radius_circle * radius_circle);

    }

    float dx = circle.x - std::max(rectangle.x - width , std::min(circle.x, rectangle.x + width - width ));
    float dy = circle.y - std::max(rectangle.y - height, std::min(circle.y, rectangle.y + height - height ));
    return (dx * dx + dy * dy) < (radius_circle * radius_circle);

    }



