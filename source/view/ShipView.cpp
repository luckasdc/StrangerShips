
#include "ShipView.h"
#include "../controller/GameController.h"


PlayerShipView::PlayerShipView(const std::shared_ptr<GamePreferences> &preferences,
                               const std::shared_ptr<ActiveEntity> &_entityPtr) :
        ActiveEntityView(preferences, _entityPtr) {

    try {
        this->makeSprite(_preferences->_config->get_texture_playership());
    }
    catch (...) {
        throw ex::ResourceException(_preferences->_config->get_texture_playership());
    }
    // initialize the position
    this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _preferences->_window->getSize().x),
                               Transformation::transformHeight(_entityPtr->getLocation().y, _preferences->_window->getSize().y));

    this->_sprite->setOrigin(17, 12);
}

SecondPlayerShipView::SecondPlayerShipView(const std::shared_ptr<GamePreferences> &preferences,
                                           const std::shared_ptr<ActiveEntity> &_entityPtr) :
        PlayerShipView(preferences, _entityPtr) {

    try {
        this->makeSprite(_preferences->_config->get_texture_secondplayership());
    }
    catch (...) {
        throw ex::ResourceException(_preferences->_config->get_texture_secondplayership());
    }

    // initialize the position
    this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _preferences->_window->getSize().x),
                               Transformation::transformHeight(_entityPtr->getLocation().y, _preferences->_window->getSize().y));

    this->_sprite->setOrigin(17, 12);
}

EnemyShipView::EnemyShipView(const std::shared_ptr<GamePreferences> &preferences,
                             const std::shared_ptr<ActiveEntity> &_entityPtr) :
        ActiveEntityView(preferences, _entityPtr) {

    try {
        this->makeSprite(_preferences->_config->get_texture_enemyship());
    }
    catch (...) {
        throw ex::ResourceException(_preferences->_config->get_texture_enemyship());
    }
    // initialize the position
    this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _preferences->_window->getSize().x),
                               Transformation::transformHeight(_entityPtr->getLocation().y, _preferences->_window->getSize().y));

    this->_sprite->setOrigin(17, 12);
}

BossEnemyShipView::BossEnemyShipView(const std::shared_ptr<GamePreferences> &preferences,
                                     const std::shared_ptr<ActiveEntity> &_entityPtr) : EnemyShipView(preferences, _entityPtr) {
    try {
        this->makeSprite(_preferences->_config->get_texture_bossbird());
    }
    catch (...) {
        throw ex::ResourceException(_preferences->_config->get_texture_bossbird());
    }

    // initialize the position
    this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _preferences->_window->getSize().x),
                               Transformation::transformHeight(_entityPtr->getLocation().y, _preferences->_window->getSize().y));

    this->_sprite->setOrigin(17, 12);
}

void BossEnemyShipView::makeSprite(const std::string &file) {
    this->_sprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture>  texture(new sf::Texture);

    if (!texture->loadFromFile(file, sf::IntRect(0, 0, 200, 200))) {
        throw ex::ResourceException(file);
    }
    // transfer ownership of texture to EntityView
    this->_texture = std::move(texture);
    this->_sprite->setTexture(*this->_texture);
}
