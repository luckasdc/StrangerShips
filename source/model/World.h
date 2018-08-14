
#ifndef STRANGERSHIPS_WORLD_H
#define STRANGERSHIPS_WORLD_H

#include "Entity.h"
#include "Ship.h"
#include "Bullet.h"
#include "Obstacle.h"
#include "../firstAid/Level.h"

#include <memory>
#include <vector>
#include <list>

class GamePreferences;

class World : public Subject {

public:


    /**
     * @brief a constructur which takes a filename of a level, generating a Level object, parsing
     * the file and adding it to the World.
     * @param level, multiplayer
     */
    World(std::string level, bool multiplayer, std::shared_ptr<GamePreferences> preferences);


    /**
     *  @brief Initializes the world based on the Level object: constructs a PlayerShip and top/bottom Obstacles.
     */
    void loadFromLevel();

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
    * @brief Getter for the shared pointer of the the secondPlayerShip
    * @return shared_ptr<PlayerShip>
    */
    const std::shared_ptr<PlayerShip>& getSecondPlayerShip() const;

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
    * @brief Getter for the list of shared pointers of Obstaces (used for updating location of obstacles
    * and checking collisions)
    * @return std::vector<std::shared_ptr<EnemyShip>>
    */
    const std::vector<std::shared_ptr<Obstacle>> &getObstacleList() const;


    /**
     * @brief adds a bullet to the bulletList
     */
    void addBullet(std::shared_ptr<Bullet> bullet);

    /**
     * @brief removes a bullet from the bulletList
     * @param bullet
     */
    void removeBullet(std::shared_ptr<Bullet> bullet);

    /**
     * @brief adds a new enemy to the world (used by AIController)
     */
    void addEnemy();

    /**
     * @brief removes an enemy from te enemyshiplist
     * @param enemy
     */
    void removeEnemy(std::shared_ptr<EnemyShip> enemy);

    /**
     * @brief removes an obstacle from te obstacleList
     * @param obstacle
     */
    void removeObstacle(std::shared_ptr<Obstacle> obstacle);

    /**
     * @brief adds a new sporadic obstacle, this function will be called
     * by the AI-controller.
     * @param speed
     * @param xValueBottomRightCorner
     */
    void addSporadicObstacle(float speed, float xValueBottomRightCorner);

    /**
     * @brief getter for level (used by Enemies and PlayerShip etc
     * @return unique ptr level
     */
    const std::shared_ptr<Level> &get_level() const;

    /**
     * @brief increment score with 1 point, called when enemy is hit
     */
    void incrementScore();

    /**
     * @brief score getter
     * @return score
     */
    int getScore() const;




private:
    std::shared_ptr<PlayerShip> _playerShip;
    std::shared_ptr<PlayerShip> _secondPlayerShip;
    std::vector<std::shared_ptr<EnemyShip>> _enemyShipList;
    std::vector<std::shared_ptr<Bullet>> _bulletList;
    std::vector<std::shared_ptr<Obstacle>> _obstacleList;
    std::shared_ptr<Level> _level;
    std::shared_ptr<GamePreferences> _preferences;
    bool _multiplayer;
    int score = 0;


};


#endif //STRANGERSHIPS_WORLD_H
