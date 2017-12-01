//
// Created by Luckas Declerck on 13/11/17.
//

#ifndef STRANGERSHIPS_WORLD_H
#define STRANGERSHIPS_WORLD_H


#include "Entity.h"
#include "Ship.h"
#include "Bullet.h"
#include "Obstacle.h"
#include <memory>
#include <vector>

class World : public PassiveEntity {


private:
    std::shared_ptr<PlayerShip> _playerShip;
    std::vector<std::shared_ptr<EnemyShip>> _enemyShipList;
    std::vector<std::shared_ptr<Bullet>> _bulletList;
    std::vector<std::shared_ptr<Obstacle>> _obstacleList;

};


#endif //STRANGERSHIPS_WORLD_H
