//
// Created by Luckas Declerck on 1/12/17.
//

#ifndef STRANGERSHIPS_SHIPVIEW_H
#define STRANGERSHIPS_SHIPVIEW_H


#include "View.h"
#include "EntityView.h"

#include <utility>

class PlayerShipView : public EntityView {
    /**
     * @brief default constructor of a PlayerShipView
     * @param shared_ptr<window>
     * @param shared_ptr<playerShip>
     */

public:
    PlayerShipView(const std::shared_ptr<sf::RenderWindow> &window, const std::shared_ptr<ActiveEntity> &_entityPtr,
                   const std::shared_ptr<sf::Sprite> &_sprite) : EntityView( window, _entityPtr,
                                                                            _sprite) {

        this->makeSprite("../assets/plane.png");
    }



private:

};


class EnemyShipView : public EntityView {

public:
    /**
 * @brief default constructor of a EnemyShipView
 * @param shared_ptr<window>
 * @param shared_ptr<playerShip>
 */
    EnemyShipView(const std::shared_ptr<sf::RenderWindow> &window, const std::shared_ptr<ActiveEntity> &_entityPtr,
                   const std::shared_ptr<sf::Sprite> &_sprite) : EntityView( window, _entityPtr,
                                                                             _sprite) {

        this->makeSprite("../assets/enemy.png");
    }

};


#endif //STRANGERSHIPS_SHIPVIEW_H
