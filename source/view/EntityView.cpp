
#include <iostream>
#include <cmath>
#include "EntityView.h"
/*
 * ENTITYVIEW
 */

void EntityView::makeSprite(const std::string &file) {
    this->_sprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture>  texture(new sf::Texture);

    try {
        if (!texture->loadFromFile(file, sf::IntRect(0, 0, 150, 150))) {
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

void EntityView::draw() {

    // Draw sprite on the screen
    this->_window->draw(*_sprite);
}

/*
 * ActiveEntityView
 */

void ActiveEntityView::update(std::string what) {

    //std::cout << "update! the model has notified the following: " << what << std::endl;

    if (what == "movement") {
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x, _window->getSize().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y, _window->getSize().y));
    }

    if (what == "destruction") {
        //  something?

    }
}

const std::shared_ptr<ActiveEntity> &ActiveEntityView::get_entityPtr() const {
    return _entityPtr;
}

/*
 * PassiveEntityView
 */

void PassiveEntityView::update(std::string what) {

    //std::cout << "update! the model has notified the following: " << what << std::endl;

    if (what == "shift") {
        int x = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().x, _window->getSize().x));
        int y = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().y, _window->getSize().y));
        this->_sprite->setPosition(x, y);

    }

}

void PassiveEntityView::makeSprite(const std::string &file) {
    this->_sprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture>  texture(new sf::Texture);

    int w = static_cast<int>((_entityPtr->get_width() / 8) * _window->getSize().x);
    int h = static_cast<int>((_entityPtr->get_height() / 6) * _window->getSize().y);

    try {
        if (!texture->loadFromFile(file, sf::IntRect(0, 0, w, h))){
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

const std::shared_ptr<PassiveEntity> &PassiveEntityView::get_entityPtr() const {
    return _entityPtr;
}
