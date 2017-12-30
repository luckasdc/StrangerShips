//
// Created by Luckas Declerck on 13/11/17.
//
#include <iostream>
#include "World.h"


void World::initialize() {

    _playerShip = std::make_shared<PlayerShip>();
    this->notify("newPlayership");
    _enemyShipList = {};
    _bulletList = {};
    _obstacleList = {};

    // Generate a few enemies TODO will be changed!
    for (unsigned int i = 0; i < 5; ++i) {
        _enemyShipList.push_back(std::make_shared<EnemyShip>());
        this->notify("newEnemyship");

    }

}


/// TODO COMMENTS

const std::shared_ptr<PlayerShip> &World::getPlayerShip() const {
    return _playerShip;
}

const std::shared_ptr<EnemyShip> &World::getLatestEnemyship() const {
    return _enemyShipList.back();
}
