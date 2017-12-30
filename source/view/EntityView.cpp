//
// Created by Luckas Declerck on 16/12/17.
//

#include <iostream>
#include "EntityView.h"

void EntityView::draw() {

    // First check if ship is dead or not
    if (this->_entityPtr->getHealth() == 0) return;

    // Check if sprite is already initialised
    if (this->_sprite == nullptr) return; // TODO ERROR or STANDARD INITIALISE

    // Draw sprite on the screen
    this->_window->draw(*this->_sprite);

}

void EntityView::makeSprite(const std::string &file) {

    sf::Texture texture;
    texture.loadFromFile(file);
    this->_sprite->setTexture(texture);

}

void EntityView::update(std::string what) {

    std::cout << "update! the model has notified the following: " << what << std::endl;

    if (what == "movement") {
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y));
    }

    if (what == "dead") {


    }

}
