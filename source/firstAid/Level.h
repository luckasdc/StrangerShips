
#ifndef STRANGERSHIPS_LEVEL_H
#define STRANGERSHIPS_LEVEL_H

#include "json.hpp"

class Level {

public:
    /**
     * @brief This constructor will call the parseLevel()-function to instantiate
     * a level based on the given filename (of a level.json file)
     * @param filename
     */
    Level(const char *filename);

    /**
     * @brief this will read a level.json file and parses it, will throw errors
     * if something went wrong.
     * @param filename
     */
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
