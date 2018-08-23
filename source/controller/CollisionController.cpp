
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
            waitCounter = 0;
        };
    }
}

void CollisionController::checkBulletWithShips(std::shared_ptr<Bullet> bullet) {
    if (circleCollisionTest(bullet->getLocation(), _world->getPlayerShip()->getLocation()) and bullet->fromEnemy()) {
        bullet->hit(1);
        _world->getPlayerShip()->hit(1);
    }

    for (const auto enemy : _world->getEnemyShipList()) {
        if (bullet->fromEnemy()) break;
        if (circleCollisionTest(enemy->getLocation(), bullet->getLocation())) {
            bullet->hit(1);
            enemy->hit(3);
            _world->incrementScore();
        }
    }
}

void CollisionController::checkBulletRange(std::shared_ptr<Bullet> bullet) {
    if (bullet->getLocation().x == 4 or bullet->getLocation().x == -4) {
        bullet->hit(1);
    }
}

void CollisionController::checkObstacleRange(std::shared_ptr<Obstacle> obstacle) {
    if (obstacle->get_bottomRightCorner().x + obstacle->get_width() < -4) {
        _world->removeObstacle(obstacle);
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
    float radius_circle = 0.15;
    float circleDistance_x;
    float circleDistance_y;

    if (inversed) {
        circleDistance_x = abs(circle.x - (rectangle.x + width - width/2));
        circleDistance_y = abs(circle.y - (rectangle.y + height + height/2));
    } else {
        circleDistance_x = abs(circle.x - (rectangle.x + width - width/2));
        circleDistance_y = abs(circle.y - (rectangle.y ) + height/2);
    }
    if (circleDistance_x > (width/2 + radius_circle)) { return false; }
    if (circleDistance_y > (height/2 + radius_circle)) { return false; }

    if (circleDistance_x <= (width/2)) { return true; }
    if (circleDistance_y <= (height/2)) { return true; }

    double cornerDistance_sq = pow(circleDistance_x - width/2, 2) + pow(circleDistance_y + height/2, 2);

    return (cornerDistance_sq <= pow(radius_circle, 2));
}



