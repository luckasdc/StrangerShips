//
// Created by Luckas Declerck on 29/11/17.
//

#include <iostream>
#include "WorldView.h"
#include "ShipView.h"
#include "BulletView.h"
#include "ObstacleView.h"

void WorldView::draw() {

    for (const auto& passiveEntity : this->_passiveEntityViews) {
        passiveEntity->draw();
    }
    //Draw all entities
    for (const auto& entityView : this->_entityViews) {
        entityView->draw();
    }


}

void WorldView::update(std::string what) {

    if (what == "newPlayership") {
        //std::cout << "update! Added a new PlayerShipView because World made a new one" << std::endl;
        auto ps = std::make_shared<PlayerShipView> (this->_window, this->_world->getPlayerShip());
        _entityViews.push_back(ps);
    }
    if (what == "newEnemyship") {
        //std::cout << "update! Added a new EnemyShipView because World made a new one" << std::endl;
        auto es = std::make_shared<EnemyShipView> (this->_window, this->_world->getEnemyShipList().back());
        _entityViews.push_back(es);
    }
    if (what == "newBullet") {
        //std::cout << "update! Added a new Bullet has been fired" << std::endl;
        auto b = std::make_shared<BulletView> (this->_window, this->_world->getBulletList().back());
        _entityViews.push_back(b);
    }
    if (what == "newBottomObstacle") {
        auto o = std::make_shared<BorderObstacleView> (this->_window, this->_world->getObstacleList().back());
        _passiveEntityViews.push_back(o);
    }

    if (what == "EntityDestructed") {
        //std::cout << "EntityDestructed' in worldView..." << std::endl;
        for (auto ev : this->_entityViews) {
            if (ev->get_entityPtr()->getHealth() <= 0) {
                _entityViews.erase(std::remove(_entityViews.begin(), _entityViews.end(), ev), _entityViews.end());
                break;
            }
        }

    }

    if (what == "GAME OVER") {
        this->_window->close();
    }


}