//
// Created by Luckas Declerck on 13/11/17.
//
#include <iostream>
#include "World.h"


void World::initialize() {
    // Since you cannot use share_from_this in a constructor (object itself hasn't been created yet,
    // so a weak ptr will be made), We need to solve this. Paul Houx has found a solution by using
    // Lamda Functions (https://forum.libcinder.org/topic/solution-calling-shared-from-this-in-the-constructor)
    auto wptr = std::shared_ptr<World>( this, [](World*){} );
    _playerShip = std::make_shared<PlayerShip>(this);
    this->notify("newPlayership");
    _enemyShipList = {};
    _bulletList = {};
    _obstacleList = {};

     //Generate a few enemies TODO will be changed!
    for (unsigned int i = 0; i < 5; ++i) {
        _enemyShipList.push_back(std::make_shared<EnemyShip>(this));
        this->notify("newEnemyship");
    }
    //Generate Bottom Obstacles
    for (unsigned int i = 0; i < 5; ++i) {
        // the width of every obstacle is 1.5;
        _obstacleList.push_back(std::make_shared<BorderObstacle>(0.01, ((-4) + i * 2.0), false));
        this->notify("newBottomObstacle");
    }

    //Generate Top Obstacles
    for (unsigned int i = 0; i < 5; ++i) {
        // the width of every obstacle is 1.5;
        _obstacleList.push_back(std::make_shared<BorderObstacle>(0.01, ((-4) + i * 2.0), true));
        this->notify("newBottomObstacle");
    }

}


/// GETTERS AND SETTERS

const std::shared_ptr<PlayerShip> &World::getPlayerShip() const {
    return _playerShip;
}


const std::vector<std::shared_ptr<Bullet>> &World::getBulletList() const {
    return _bulletList;
}

const std::vector<std::shared_ptr<Obstacle>> &World::getObstacleList() const {
    return _obstacleList;
}

void World::addBullet(std::shared_ptr<Bullet> bullet) {
    this->_bulletList.push_back(bullet);
    this->notify("newBullet");
}

void World::removeBullet(std::shared_ptr<Bullet> bullet) {
    bullet->notify("destruction");
    this->notify("EntityDestructed");
    bullet->detach();
    _bulletList.erase(std::remove(_bulletList.begin(), _bulletList.end(), bullet), _bulletList.end());
}

void World::removeEnemy(std::shared_ptr<EnemyShip> enemy) {
    enemy->notify("destruction");
    this->notify("EntityDestructed");
    enemy->detach();
    _enemyShipList.erase(std::remove(_enemyShipList.begin(), _enemyShipList.end(), enemy), _enemyShipList.end());
}

const std::vector<std::shared_ptr<EnemyShip>> &World::getEnemyShipList() const {
    return _enemyShipList;
}

void World::updateEntities() {

    auto snapshotOfBullets = _bulletList;
    auto snapshotOfEnemies = _enemyShipList;
    auto snapshotOfObstacles = _obstacleList;


    if (_playerShip->getHealth() == 0) {
        std::cout << "PLAYERSHIP IS DEAD, GAME OVER" << std::endl;
        this->notify("GAME OVER");
    }
    for(auto& o : snapshotOfObstacles) {
        o->shiftLeft();
    }
    for (auto& es : snapshotOfEnemies) {
        if (es->getHealth() == 0) {
            this->removeEnemy(es);
        }
    }
    for (auto& b : snapshotOfBullets) {
        if (b->getHealth() == 0) {
            this->removeBullet(b);
        }
    }


}



