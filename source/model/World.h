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

private:
    std::shared_ptr<PlayerShip> _playerShip;
    std::vector<std::shared_ptr<EnemyShip>> _enemyShipList;
    std::vector<std::shared_ptr<Bullet>> _bulletList;
    std::vector<std::shared_ptr<Obstacle>> _obstacleList;

public:

    /**
     * @brief A default, empty constructor since initialize() handles all the entities in the world.
     */
    World() = default;

    /**
    * @brief Initializes the current level: constructs a PlayerShip, the EnemyShips and the Obstacles.
     * It also notifies the Observers.
    *
    */
    void initialize();

    /**
    * @brief Getter for the shared pointer of the PlayerShip
    * @return shared_ptr<PlayerShip>
    */
    const std::shared_ptr<PlayerShip>& getPlayerShip() const;

    /**
    * @brief Getter for the shared pointer of the latest added EnemyShip (used for notifying observers)
    * @return shared_ptr<EnemyShip>
    */
    const std::shared_ptr<EnemyShip>& getLatestEnemyship() const;


};


#endif //STRANGERSHIPS_WORLD_H
