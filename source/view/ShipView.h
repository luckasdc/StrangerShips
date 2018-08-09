
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
    PlayerShipView(const std::shared_ptr<sf::RenderWindow> &window, const std::shared_ptr<ActiveEntity> &_entityPtr) :
            ActiveEntityView( window, _entityPtr) {

        this->makeSprite("../assets/bluebird-midflap.png");
        // initialize the position
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _window->getSize().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y, _window->getSize().y));

        this->_sprite->setOrigin(17, 12);
    }


};

class SecondPlayerShipView : public PlayerShipView {

public:

    /**
     * @brief default constructor of a PlayerShipView
     * @param shared_ptr<window>
     * @param shared_ptr<playerShip>
     */
    SecondPlayerShipView(const std::shared_ptr<sf::RenderWindow> &window,
                         const std::shared_ptr<ActiveEntity> &_entityPtr) :
            PlayerShipView(window, _entityPtr) {

        this->makeSprite("../assets/yellowbird-midflap.png");
        // initialize the position
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _window->getSize().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y, _window->getSize().y));

        this->_sprite->setOrigin(17, 12);
    }


};



class EnemyShipView : public ActiveEntityView {

public:
    /**
 * @brief default constructor of a EnemyShipView
 * @param shared_ptr<window>
 * @param shared_ptr<playerShip>
 */
    EnemyShipView(const std::shared_ptr<sf::RenderWindow> &window, const std::shared_ptr<ActiveEntity> &_entityPtr) :
            ActiveEntityView( window, _entityPtr) {

        this->makeSprite("../assets/angrybird.png");

        // initialize the position
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _window->getSize().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y, _window->getSize().y));

        this->_sprite->setOrigin(17, 12);
    }

};


#endif //STRANGERSHIPS_SHIPVIEW_H
