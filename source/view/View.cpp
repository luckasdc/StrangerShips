//
// Created by Luckas Declerck on 29/11/17.
//

#include "View.h"

void View::makeSprite(const std::string &file) {

    sf::Texture texture;
    texture.loadFromFile(file);
    this->_sprite->setTexture(texture);

}
