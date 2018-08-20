
#include <iostream>
#include "OverlayView.h"
#include "../controller/GameController.h"
#include "../firstAid/Settings.h"
#include "../firstAid/Exception.h"

void OverlayView::drawLives() {

    int health = static_cast<int>(_world->getPlayerShip()->getHealth());
    _heartSprite->setPosition(50, _preferences->_window->getSize().y - 50);

    for (int i = 0; i < health; i++) {
        auto newHeart = _heartSprite;
        newHeart->setPosition(50 + (i * 30), _preferences->_window->getSize().y - 50);
        _preferences->_window->draw(*newHeart);
    }
}

void OverlayView::initHeart() {
    // make sprite
    this->_heartSprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture> texture(new sf::Texture);

    if (!texture->loadFromFile(_preferences->_config->get_texture_heart(), sf::IntRect(0, 0, _preferences->_window->getSize().x, _preferences->_window->getSize().y))){
        throw ex::ResourceException(_preferences->_config->get_texture_heart());
    }
    // transfer ownership of texture to EntityView
    this->_heartTexture = std::move(texture);
    this->_heartSprite->setTexture(*this->_heartTexture);
}

void OverlayView::drawScore() {
    _scoreText.setString(std::to_string(_world->getScore()));
    _preferences->_window->draw(_scoreText);
}

void OverlayView::initScore() {
    if (!_font.loadFromFile(_preferences->_config->get_font())) {
        throw ex::ResourceException(_preferences->_config->get_font());
    };
    _scoreText.setFont(_font);
    _scoreText.setString(std::to_string(_world->getScore()));
    _scoreText.setCharacterSize(56);
    _scoreText.setColor(sf::Color::Red);
    _scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
    _scoreText.setPosition(sf::Vector2f(_preferences->width / 10 * 9, _preferences->height - 60));
}

void OverlayView::initLevelText() {

    if (!_font.loadFromFile(_preferences->_config->get_font())) {
        throw ex::ResourceException(_preferences->_config->get_font());
    }
    _levelText.setFont(_font);
    _levelText.setString(_preferences->_config->get_levels()[_preferences->currentLevel].name);
    _levelText.setCharacterSize(56);
    _levelText.setColor(sf::Color::Black);
    _levelText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
    _levelText.setPosition(sf::Vector2f(30,  30));
}

void OverlayView::drawLevel() {
    _preferences->_window->draw(_levelText);
}
