

#include <fstream>
#include "Level.h"
#include "Exception.h"

using json = nlohmann::json;

Level::Level(std::string filename) {
    this->parseLevel(filename);
}

void Level::parseLevel(std::string filename) {

    json j;
    try {
        std::ifstream i (filename);
        i >> j;
    }
    catch (...) {
        throw ex::LevelFileException(filename);
    }

    std::string entry;
    try {
        entry = "_level";
        _level = j["Level"].get<int>();
        entry = "_initialEnemies";
        _initialEnemies = j["InitialEnemies"].get<int>();
        entry = "_enemiesInWave";
        _enemiesInWave = j["EnemiesInWave"].get<int>();
        entry = "_amountOfWaves";
        _amountOfWaves = j["AmountOfWaves"].get<int>();
        entry = "_enemyShipSpeed";
        _enemyShipSpeed = j["EnemyShipSpeed"].get<float>();
        entry = "_playerShipSpeed";
        _playerShipSpeed = j["PlayerShipSpeed"].get<float>();
        entry = "_sporadicObstacleSpeed";
        _sporadicObstacleSpeed = j["SporadicObstacleSpeed"].get<float>();
    }
    catch (std::runtime_error& e) {
        throw ex::LevelEntryException(filename, entry);
    }
}

int Level::get_level() const {
    return _level;
}

int Level::get_initialEnemies() const {
    return _initialEnemies;
}

int Level::get_enemiesInWave() const {
    return _enemiesInWave;
}

int Level::get_amountOfWaves() const {
    return _amountOfWaves;
}

float Level::get_enemyShipSpeed() const {
    return _enemyShipSpeed;
}

float Level::get_playerShipSpeed() const {
    return _playerShipSpeed;
}

float Level::get_sporadicObstacleSpeed() const {
    return _sporadicObstacleSpeed;
}


