//
// Created by Luckas Declerck on 29/11/17.
//

#include <iostream>
#include "WorldView.h"
#include "ShipView.h"


void WorldView::draw() {

    //Draw all entities
    for (const auto& entityView : this->_entityViews) {
        entityView->draw();
    }


}

void WorldView::update(std::string what) {

    if (what == "newPlayership") {
        std::cout << "update! Added a new PlayerShipView because World made a new one" << std::endl;
        _entityViews.push_back(std::make_shared<PlayerShipView> (this->_window, this->_world->getPlayerShip()));
    }
    if (what == "newEnemyship") {
        std::cout << "update! Added a new EnemyShipView because World made a new one" << std::endl;
        _entityViews.push_back(std::make_shared<EnemyShipView> (this->_window, this->_world->getLatestEnemyship()));
    }


}
