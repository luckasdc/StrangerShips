//
// Created by Luckas Declerck on 31/11/17.
//

#ifndef STRANGERSHIPS_BULLETVIEW_H
#define STRANGERSHIPS_BULLETVIEW_H


#include "EntityView.h"

class BulletView : public EntityView {

public:
    /**
    * @brief default constructor of a BulletView
    * @param shared_ptr<window>
    * @param shared_ptr<Bullet>
    */
    BulletView(const std::shared_ptr<sf::RenderWindow> &window, const std::shared_ptr<ActiveEntity> &_entityPtr) :
            EntityView( window, _entityPtr) {

        this->makeSprite("../assets/bullet.png");
        // initialize the position
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _window->getSize().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y, _window->getSize().y));

        this->_sprite->setOrigin(25, 25);
    }
};


#endif //STRANGERSHIPS_BULLETVIEW_H
