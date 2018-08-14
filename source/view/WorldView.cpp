
#include <iostream>
#include "WorldView.h"
#include "ShipView.h"
#include "BulletView.h"
#include "ObstacleView.h"
#include "OverlayView.h"

#include "../controller/StateManager.h"

void WorldView::draw() {

    _preferences->_window->draw(*_BgSprite);

    for (const auto& passiveEntity : this->_passiveEntityViews) {
        passiveEntity->draw();
    }
    //Draw all entities
    for (const auto& entityView : this->_entityViews) {
        entityView->draw();
    }
    _overlay->drawLives();
    _overlay->drawScore();

}

void WorldView::update(std::string what) {

    if (what == "newPlayership") {
        auto ps = std::make_shared<PlayerShipView> (_preferences, this->_world->getPlayerShip());
        _entityViews.push_back(ps);
    }
    if (what == "newSecondPlayership") {
        auto ps = std::make_shared<SecondPlayerShipView> (_preferences, this->_world->getSecondPlayerShip());
        _entityViews.push_back(ps);
    }
    if (what == "newEnemyship") {
        auto es = std::make_shared<EnemyShipView> (_preferences, this->_world->getEnemyShipList().back());
        _entityViews.push_back(es);
    }
    if (what == "newBullet") {
        auto b = std::make_shared<BulletView> (_preferences, this->_world->getBulletList().back());
        _entityViews.push_back(b);
    }
    if (what == "newBottomObstacle") {
        auto o = std::make_shared<BorderObstacleView> (_preferences, this->_world->getObstacleList().back());
        _passiveEntityViews.push_back(o);
    }
    if (what == "newSporadicObstacle") {
        auto o = std::make_shared<SporadicObstacleView> (_preferences, this->_world->getObstacleList().back());
        _passiveEntityViews.push_back(o);
    }
    if (what == "EntityDestructed") {
        for (auto ev : this->_entityViews) {
            if (ev->get_entityPtr()->getHealth() <= 0) {
                _entityViews.erase(std::remove(_entityViews.begin(), _entityViews.end(), ev), _entityViews.end());
                break;
            }
        }
    }
    if (what == "ObstacleDestruction") {
        for (auto pe : this->_passiveEntityViews) {
            if (pe->get_entityPtr()->get_bottomRightCorner().x + pe->get_entityPtr()->get_width() < -4) {
                _passiveEntityViews.erase(std::remove(_passiveEntityViews.begin(), _passiveEntityViews.end(), pe), _passiveEntityViews.end());
                break;
            }
        }
    }

}

void WorldView::initBackground() {
    // make sprite
    this->_BgSprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture> texture(new sf::Texture);

    try {
        if (!texture->loadFromFile("../assets/" + _preferences->_config->get_texture_background(), sf::IntRect(0, 0, _preferences->_window->getSize().x, _preferences->_window->getSize().y))){
            throw std::runtime_error("Could not load texture from file");
        }
    }
    catch (std::runtime_error& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }

    // transfer ownership of texture to EntityView
    this->_BgTexture = std::move(texture);
    this->_BgSprite->setTexture(*this->_BgTexture);

}

WorldView::WorldView(const std::shared_ptr<World> &world, std::shared_ptr<GamePreferences>& preferences)
        : Observer(world), _world(world), _preferences(preferences)  {
        initBackground();
        _overlay = std::make_shared<OverlayView>(_preferences, _world);

        }
