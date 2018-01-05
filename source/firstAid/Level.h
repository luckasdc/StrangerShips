
#ifndef STRANGERSHIPS_LEVEL_H
#define STRANGERSHIPS_LEVEL_H

#include "json.hpp"

class Level {

public:

    Level(const char *filename);

    void parseLevel(const char * filename);

    int get_level() const;

    int get_initialEnemies() const;

    int get_enemiesInWave() const;

    int get_amountOfWaves() const;

    float get_enemyShipSpeed() const;

    float get_playerShipSpeed() const;

    float get_sporadicObstacleSpeed() const;

private:

    int _level{};
    int _initialEnemies{};
    int _enemiesInWave{};
    int _amountOfWaves{};

    float _enemyShipSpeed{};
    float _playerShipSpeed{};
    float _sporadicObstacleSpeed{};

};


#endif //STRANGERSHIPS_LEVEL_H