
#include <iostream>
#include "World.h"
#include "../controller/State.h"
#include "../controller/StateManager.h"
#include "../controller/GameController.h"


World::World(std::string level, bool multiplayer, std::shared_ptr<GamePreferences> preferences) {

    _level = std::make_shared<Level> (level);
    _multiplayer = multiplayer;
    _preferences = preferences;

}

void World::loadFromLevel() {

    // generating a PlayerShip
    // Since you cannot use share_from_this in a constructor (object itself hasn't been created yet,
    // so a weak ptr will be made), We need to solve this. Paul Houx has found a solution by using
    // Lamda Functions (https://forum.libcinder.org/topic/solution-calling-shared-from-this-in-the-constructor)
    auto wptr = std::shared_ptr<World>( this, [](World*){} );
    _playerShip = std::make_shared<PlayerShip>(this);
    this->notify("newPlayership");

    // generate a second playership in case of multiplayer
    if (_multiplayer) {
        _secondPlayerShip = std::make_shared<SecondPlayerShip>(this);
        this->notify("newSecondPlayership");
    }

    _enemyShipList = {};
    _bulletList = {};
    _obstacleList = {};

    //Generate Bottom Obstacles !NOTE! these iterations are necessary to create a full-width border, it's not meant to be changed
    for (unsigned int i = 0; i < 5; ++i) {
        _obstacleList.push_back(std::make_shared<BorderObstacle>(0.01, ((-4) + i * 2.0), false));
        this->notify("newBottomObstacle");
    }

    //Generate Top Obstacles !NOTE! these iterations are necessary to create a full-width border, it's not meant to be changed
    for (unsigned int i = 0; i < 5; ++i) {
        _obstacleList.push_back(std::make_shared<BorderObstacle>(0.01, ((-4) + i * 2.0), true));
        this->notify("newBottomObstacle");
    }

    // set initial amount of Enemies
    for (unsigned int i = 0; i < _level->get_initialEnemies(); ++i) {
        _enemyShipList.push_back(std::make_shared<EnemyShip>(this));
        this->notify("newEnemyship");
    }


}

/// GETTERS AND SETTERS

const std::shared_ptr<PlayerShip> &World::getPlayerShip() const {
    return _playerShip;
}

const std::shared_ptr<PlayerShip> &World::getSecondPlayerShip() const {
    return _secondPlayerShip;
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

void World::addEnemy() {
    _enemyShipList.push_back(std::make_shared<EnemyShip>(this));
    this->notify("newEnemyship");
}


void World::removeEnemy(std::shared_ptr<EnemyShip> enemy) {
    enemy->notify("destruction");
    this->notify("EntityDestructed");
    enemy->detach();
    _enemyShipList.erase(std::remove(_enemyShipList.begin(), _enemyShipList.end(), enemy), _enemyShipList.end());
}

void World::removeObstacle(std::shared_ptr<Obstacle> obstacle) {
    obstacle->notify("destruction");
    this->notify("ObstacleDestruction");
    obstacle->detach();
    _obstacleList.erase(std::remove(_obstacleList.begin(), _obstacleList.end(), obstacle), _obstacleList.end());
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
        _preferences->stateManager->popState();
        _preferences->stateManager->pushState(std::make_unique<ScoresState>(_preferences, this->score));


        //this->notify("GAME OVER");
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

void World::addSporadicObstacle(float speed, float xValueBottomRightCorner) {
    auto o = std::make_shared<SporadicObstacle>(speed, xValueBottomRightCorner);
    this->_obstacleList.push_back(o);
    this->notify("newSporadicObstacle");
}

const std::shared_ptr<Level> &World::get_level() const {
    return _level;
}

void World::incrementScore() {
    this->score++;
}

int World::getScore() const {
    return score;
}









