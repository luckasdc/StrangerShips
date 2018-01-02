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

class World : public Subject {

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
     * @brief checks if all enitities are still alive and removes them if they are not.
     */
    void updateEntities();

    /**
    * @brief Getter for the shared pointer of the PlayerShip
    * @return shared_ptr<PlayerShip>
    */
    const std::shared_ptr<PlayerShip>& getPlayerShip() const;

    /**
    * @brief Getter for the list of shared pointers of EnemyShips (used for notifying observers)
    * @return vector<shared_ptr<EnemyShip>>
    */
    const std::vector<std::shared_ptr<EnemyShip>>& getEnemyShipList() const;

    /**
   * @brief Getter for the list of shared pointers of bullets (used for updating location of bullets
   * and checking collisions)
   * @return std::vector<std::shared_ptr<EnemyShip>>
   */
    const std::vector<std::shared_ptr<Bullet>> &getBulletList() const;

    /**
     * @brief adds a bullet to the bulletList
     *
     */
    void addBullet(std::shared_ptr<Bullet> bullet);

    /**
     * @brief removes a bullet from the bulletList
     * @param bullet
     */
    void removeBullet(std::shared_ptr<Bullet> bullet);

    /**
     * @brief removes an enemy from te enemyshiplist
     * @param enemy
     */
    void removeEnemy(std::shared_ptr<EnemyShip> enemy);


    };


#endif //STRANGERSHIPS_WORLD_H
