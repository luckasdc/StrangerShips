
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
    ~PlayerShipView() override = default;
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
    ~SecondPlayerShipView() override = default;

};


class EnemyShipView : public ActiveEntityView {
public:
    /**
     * @brief default constructor of a EnemyShipView
     * @param shared_ptr<window>
     * @param shared_ptr<EnemyShip>
     */
    EnemyShipView(const std::shared_ptr<GamePreferences> &preferences, const std::shared_ptr<ActiveEntity> &_entityPtr);
    ~EnemyShipView() override = default;

};


class BossEnemyShipView : public EnemyShipView {
public:
    /**
    * @brief default constructor of a BossEnemyShipView
    * @param shared_ptr<window>
    * @param shared_ptr<BossEnemyShop>
    */
    BossEnemyShipView(const std::shared_ptr<GamePreferences> &preferences, const std::shared_ptr<ActiveEntity> &_entityPtr);
    ~BossEnemyShipView() override = default;

    void makeSprite(const std::string &file) override;
};

#endif //STRANGERSHIPS_SHIPVIEW_H
