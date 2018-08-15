
#include "ShipView.h"
#include "../controller/GameController.h"


PlayerShipView::PlayerShipView(const std::shared_ptr<GamePreferences> &preferences,
                               const std::shared_ptr<ActiveEntity> &_entityPtr) :
        ActiveEntityView(preferences, _entityPtr) {

    this->makeSprite("../assets/" + _preferences->_config->get_texture_playership());
    // initialize the position
    this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _preferences->_window->getSize().x),
                               Transformation::transformHeight(_entityPtr->getLocation().y, _preferences->_window->getSize().y));

    this->_sprite->setOrigin(17, 12);
}

SecondPlayerShipView::SecondPlayerShipView(const std::shared_ptr<GamePreferences> &preferences,
                                           const std::shared_ptr<ActiveEntity> &_entityPtr) :
        PlayerShipView(preferences, _entityPtr) {

    this->makeSprite("../assets/" + _preferences->_config->get_texture_secondplayership());
    // initialize the position
    this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _preferences->_window->getSize().x),
                               Transformation::transformHeight(_entityPtr->getLocation().y, _preferences->_window->getSize().y));

    // TODO NO HARDCODE
    this->_sprite->setOrigin(17, 12);
}

EnemyShipView::EnemyShipView(const std::shared_ptr<GamePreferences> &preferences,
                             const std::shared_ptr<ActiveEntity> &_entityPtr) :
        ActiveEntityView(preferences, _entityPtr) {

    this->makeSprite("../assets/" + _preferences->_config->get_texture_enemyship());

    // initialize the position
    this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _preferences->_window->getSize().x),
                               Transformation::transformHeight(_entityPtr->getLocation().y, _preferences->_window->getSize().y));

    // TODO NO HARDCODE
    this->_sprite->setOrigin(17, 12);
}