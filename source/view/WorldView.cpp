//
// Created by Luckas Declerck on 29/11/17.
//

#include <iostream>
#include "WorldView.h"
#include "ShipView.h"
#include "BulletView.h"

void WorldView::draw() {

    //Draw all entities
    for (const auto& entityView : this->_entityViews) {
        entityView->draw();
    }


}

void WorldView::update(std::string what) {

    if (what == "newPlayership") {
        std::cout << "update! Added a new PlayerShipView because World made a new one" << std::endl;
        auto ps = std::make_shared<PlayerShipView> (this->_window, this->_world->getPlayerShip());
        //_world->getPlayerShip()->attach(ps);
        _entityViews.push_back(ps);
    }
    if (what == "newEnemyship") {
        std::cout << "update! Added a new EnemyShipView because World made a new one" << std::endl;
        auto es = std::make_shared<EnemyShipView> (this->_window, this->_world->getLatestEnemyship());
        //_world->getLatestEnemyship()->attach(es);
        _entityViews.push_back(es);
    }
    if (what == "newBullet") {
        std::cout << "update! Added a new Bullet has been fired" << std::endl;
        auto b = std::make_shared<BulletView> (this->_window, this->_world->getBulletList().back());
        //_world->getLatestEnemyship()->attach(es);
        _entityViews.push_back(b);
    }

    if (what == "EntityDestructed") {
        //std::cout << "EntityDestructed' in worldView..." << std::endl;
        for (auto ev : this->_entityViews) {
            if (ev->get_entityPtr()->getHealth() == 0) {
                _entityViews.erase(std::remove(_entityViews.begin(), _entityViews.end(), ev), _entityViews.end());
                break;
            }
        }

    }


}
