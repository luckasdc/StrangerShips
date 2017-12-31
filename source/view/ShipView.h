//
// Created by Luckas Declerck on 1/12/17.
//

#ifndef STRANGERSHIPS_SHIPVIEW_H
#define STRANGERSHIPS_SHIPVIEW_H


#include "WorldView.h"
#include "EntityView.h"

#include <utility>

class PlayerShipView : public EntityView {

public:

    /**
     * @brief default constructor of a PlayerShipView
     * @param shared_ptr<window>
     * @param shared_ptr<playerShip>
     */
    PlayerShipView(const std::shared_ptr<sf::RenderWindow> &window, const std::shared_ptr<ActiveEntity> &_entityPtr) :
            EntityView( window, _entityPtr) {

        this->makeSprite("../assets/plane.png");
        // initialize the position
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _window->getSize().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y, _window->getSize().y));

        this->_sprite->setOrigin(75, 75);
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
    EnemyShipView(const std::shared_ptr<sf::RenderWindow> &window, const std::shared_ptr<ActiveEntity> &_entityPtr) :
            EntityView( window, _entityPtr) {

        this->makeSprite("../assets/enemy.png");

        // initialize the position
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _window->getSize().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y, _window->getSize().y));

    }

};


#endif //STRANGERSHIPS_SHIPVIEW_H
