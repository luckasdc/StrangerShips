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
#include <list>

class World : public PassiveEntity {

    typedef std::vector<std::shared_ptr<ActiveEntity> > EntityList;


private:
    std::shared_ptr<PlayerShip> _playerShip;
    EntityList _enemyShipList;
    std::shared_ptr<EntityList> _bulletList;
    std::shared_ptr<EntityList> _obstacleList;

public:

    // Constructor
    World();

    // update() --> calls update-functions of items
    void update();

    void checkIfInitialised();

    const std::shared_ptr<PlayerShip> &get_playerShip() const;


};


#endif //STRANGERSHIPS_WORLD_H
