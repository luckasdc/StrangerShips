//
// Created by Luckas Declerck on 16/12/17.
//

#include <iostream>
#include "EntityView.h"

void EntityView::draw() {

    // First check if ship is dead or not
    if (this->_entityPtr->getHealth() == 0) return;

    // Draw sprite on the screen
    this->_window->draw(*_sprite);

}

void EntityView::makeSprite(const std::string &file) {
    std::cout << "makeSprite! loading from file " << file << std::endl;
    this->_sprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture>  texture(new sf::Texture);
    try {
        if (!texture->loadFromFile(file, sf::IntRect(0, 0, 500, 500))) {
            throw std::runtime_error("Could not load texture from file");
        }

    }
    catch (std::runtime_error& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }
    // transfer ownership of texture to EntityView
    this->_texture = std::move(texture);
    this->_sprite->setTexture(*this->_texture);

}

void EntityView::update(std::string what) {

    //std::cout << "update! the model has notified the following: " << what << std::endl;

    if (what == "movement") {
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _window->getSize().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y, _window->getSize().y));
//        std::cout << "Model Location: " << _entityPtr->getLocation().x << ", " << _entityPtr->getLocation().y << std::endl;
//        std::cout << "Screen Location: " << Transformation::transformWidth(_entityPtr->getLocation().x , _window->getSize().x) << ", " <<
//                Transformation::transformHeight(_entityPtr->getLocation().y, _window->getSize().y) << std::endl;

    }

    if (what == "destruction") {
        std::cout << "destruction' in entityview!" << std::endl;

    }

}

const std::shared_ptr<ActiveEntity> &EntityView::get_entityPtr() const {
    return _entityPtr;
}
