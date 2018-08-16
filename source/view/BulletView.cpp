
#include "BulletView.h"
#include "../controller/GameController.h"


BulletView::BulletView(const std::shared_ptr<GamePreferences> &preferences,
                       const std::shared_ptr<ActiveEntity> &_entityPtr) :
        ActiveEntityView(preferences, _entityPtr) {

    try {
        this->makeSprite(_preferences->_config->get_texture_bullet());
    } catch (...) {
        throw ex::ResourceException(_preferences->_config->get_texture_bullet());
    }
    // initialize the position
    this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _preferences->_window->getSize().x),
                               Transformation::transformHeight(_entityPtr->getLocation().y, _preferences->_window->getSize().y));

    this->_sprite->setOrigin(17, 12);
}