//
// Created by Luckas Declerck on 29/11/17.
//

#ifndef STRANGERSHIPS_VIEW_H
#define STRANGERSHIPS_VIEW_H

#include <utility>

#include "../model/World.h"
#include "../model/Entity.h"
#include "SFML/Graphics.hpp"
#include "../model/Subject.h"

class View : public Observer {

public:
// TODO add texture manager
    /**
     * @brief constructor for base-class View
     * @param window
     */
    View(std::shared_ptr<Subject> _subject, std::shared_ptr<sf::RenderWindow> window)
            : Observer(std::move(_subject)), _window(std::move(window)) {}


    /**
     * @brief initialises a sprite based on the given filename;
     * @param string path + filename
     */
    virtual void makeSprite(const std::string& file);

    /**
     * @brief virtual function for drawing objects onto the screen
     */
    virtual void draw() = 0;



protected:
    std::shared_ptr<sf::RenderWindow> _window;
    std::unique_ptr<sf::Sprite> _sprite = nullptr;

};


#endif //STRANGERSHIPS_VIEW_H
