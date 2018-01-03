
#include <iostream>
#include "OverlayView.h"

void OverlayView::drawLives() {

    int health = static_cast<int>(_world->getPlayerShip()->getHealth());
    _heartSprite->setPosition(50, _window->getSize().y - 50);

    for (int i = 0; i < health; i++) {
        auto newHeart = _heartSprite;
        newHeart->setPosition(50 + (i * 30), _window->getSize().y - 50);
        _window->draw(*newHeart);
    }

}

void OverlayView::initHeart() {
    // make sprite
    this->_heartSprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture> texture(new sf::Texture);

    try {
        if (!texture->loadFromFile("../assets/heart.png", sf::IntRect(0, 0, _window->getSize().x, _window->getSize().y))){
            throw std::runtime_error("Could not load texture from file");
        }
    }
    catch (std::runtime_error& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }


    // transfer ownership of texture to EntityView
    this->_heartTexture = std::move(texture);
    this->_heartSprite->setTexture(*this->_heartTexture);

}