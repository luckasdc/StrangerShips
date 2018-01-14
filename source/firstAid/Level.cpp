

#include <fstream>
#include "Level.h"

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
    catch (std::runtime_error& e) {
        std::cerr << "Fatal error loading file: " << e.what() << std::endl;
    }

    try {
        _level = j["Level"].get<int>();
        _initialEnemies = j["InitialEnemies"].get<int>();
        _enemiesInWave = j["EnemiesInWave"].get<int>();
        _amountOfWaves = j["AmountOfWaves"].get<int>();

        _enemyShipSpeed = j["EnemyShipSpeed"].get<float>();
        _playerShipSpeed = j["PlayerShipSpeed"].get<float>();
        _sporadicObstacleSpeed = j["SporadicObstacleSpeed"].get<float>();
    }
    catch (std::runtime_error& e) {
        std::cerr << "Fatal error parsing values in file: " << e.what() << std::endl;
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


