//
// Created by Luckas Declerck on 1/12/17.
//

#include "ShipView.h"


void PlayerShipView::draw() {

    // First check if ship is dead or not
    if (this->_playerShip->getHealth() == 0) return;

    // Check if sprite is already initialised
    if (this->_sprite == nullptr) return; // TODO ERROR or STANDARD INITIALISE

    // Get location of model and assign it to sprite
    // TODO: TRANSFORMATION CLASS
    this->_sprite->setPosition(_playerShip->getLocation().x,
                               _playerShip->getLocation().y);

    // Draw sprite on the screen
    this->_window->draw(*this->_sprite);

}
