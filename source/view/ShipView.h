
#ifndef STRANGERSHIPS_SHIPVIEW_H
#define STRANGERSHIPS_SHIPVIEW_H


#include "WorldView.h"
#include "EntityView.h"
#include <utility>

class PlayerShipView : public ActiveEntityView {

public:

    /**
     * @brief default constructor of a PlayerShipView
     * @param shared_ptr<window>
     * @param shared_ptr<playerShip>
     */
    PlayerShipView(const std::shared_ptr<GamePreferences> &preferences, const std::shared_ptr<ActiveEntity> &_entityPtr);
};

class SecondPlayerShipView : public PlayerShipView {

public:

    /**
     * @brief default constructor of a PlayerShipView
     * @param shared_ptr<window>
     * @param shared_ptr<playerShip>
     */
    SecondPlayerShipView(const std::shared_ptr<GamePreferences> &preferences,
                         const std::shared_ptr<ActiveEntity> &_entityPtr);


};



class EnemyShipView : public ActiveEntityView {

public:
    /**
     * @brief default constructor of a EnemyShipView
     * @param shared_ptr<window>
     * @param shared_ptr<EnemyShip>
     */
    EnemyShipView(const std::shared_ptr<GamePreferences> &preferences, const std::shared_ptr<ActiveEntity> &_entityPtr);

};

class BossEnemyShipView : public EnemyShipView {

public:

    /**
    * @brief default constructor of a BossEnemyShipView
    * @param shared_ptr<window>
    * @param shared_ptr<BossEnemyShop>
    */
    BossEnemyShipView(const std::shared_ptr<GamePreferences> &preferences, const std::shared_ptr<ActiveEntity> &_entityPtr);

    void makeSprite(const std::string &file);
};


#endif //STRANGERSHIPS_SHIPVIEW_H
