
#include <iostream>
#include <cmath>
#include "EntityView.h"
#include "../controller/GameController.h"
/*
 * ENTITYVIEW
 */

void EntityView::makeSprite(const std::string &file) {
    this->_sprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture>  texture(new sf::Texture);

    if (!texture->loadFromFile(file, sf::IntRect(0, 0, 150, 150))) {
        throw ex::ResourceException(file);
    }

    // transfer ownership of texture to EntityView
    this->_texture = std::move(texture);
    this->_sprite->setTexture(*this->_texture);
}

void EntityView::draw() {

    // Draw sprite on the screen
    this->_preferences->_window->draw(*_sprite);
}

/*
 * ActiveEntityView
 */

void ActiveEntityView::update(std::string what) {

    if (what == "movement") {
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _preferences->_window->getSize().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y, _preferences->_window->getSize().y));
    }

}

const std::shared_ptr<ActiveEntity> &ActiveEntityView::get_entityPtr() const {
    return _entityPtr;
}

/*
 * PassiveEntityView
 */

void PassiveEntityView::update(std::string what) {

    if (what == "shift") {
        int x = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().x, _preferences->_window->getSize().x));
        int y = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().y, _preferences->_window->getSize().y));
        this->_sprite->setPosition(x, y);

    }
}

void PassiveEntityView::makeSprite(const std::string &file) {
    this->_sprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture>  texture(new sf::Texture);

    int w = static_cast<int>((_entityPtr->get_width() / 8) * _preferences->_window->getSize().x);
    int h = static_cast<int>((_entityPtr->get_height() / 6) * _preferences->_window->getSize().y);

        if (!texture->loadFromFile(file, sf::IntRect(0, 0, w, h))){
            throw ex::ResourceException(file);
        }


    // transfer ownership of texture to EntityView
    this->_texture = std::move(texture);
    this->_sprite->setTexture(*this->_texture);

}

const std::shared_ptr<PassiveEntity> &PassiveEntityView::get_entityPtr() const {
    return _entityPtr;
}
