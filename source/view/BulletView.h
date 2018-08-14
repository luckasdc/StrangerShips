
#ifndef STRANGERSHIPS_BULLETVIEW_H
#define STRANGERSHIPS_BULLETVIEW_H


#include "EntityView.h"
#include "../controller/GameController.h"

class BulletView : public ActiveEntityView {

public:
    /**
    * @brief default constructor of a BulletView
    * @param shared_ptr<window>
    * @param shared_ptr<Bullet>
    */
    BulletView(const std::shared_ptr<GamePreferences>& preferences, const std::shared_ptr<ActiveEntity> &_entityPtr) :
            ActiveEntityView(preferences, _entityPtr) {

        this->makeSprite("../assets/bullet.png");
        // initialize the position
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _preferences->_window->getSize().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y, _preferences->_window->getSize().y));

        this->_sprite->setOrigin(17, 12);
    }
};


#endif //STRANGERSHIPS_BULLETVIEW_H
