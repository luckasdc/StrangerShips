//
// Created by Luckas Declerck on 13/11/17.
//
#include <iostream>
#include "World.h"

World::World() {

    _playerShip = std::make_shared<PlayerShip>();
    _enemyShipList = {};
    _bulletList = {};
    _obstacleList = {};


    // Generate a few enemies TODO will be changed!
    for (unsigned int i = 0; i < 5; ++i) {
        _enemyShipList.push_back(std::make_shared<EnemyShip>());
    }

}

void World::update() {




}

void World::checkIfInitialised() {

    if (this->_playerShip != nullptr) {
        std::cout << "Ik ben een friendly ship" << std::endl;
    }
    for (auto& enShip : this->_enemyShipList) {
        std::cout << "Ik ben een enemy ship" << std::endl;
    }

}


///TODO WEGHALEN HIERONDER

const std::shared_ptr<PlayerShip> &World::get_playerShip() const {
    return _playerShip;
}
