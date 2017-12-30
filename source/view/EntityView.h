//
// Created by Luckas Declerck on 16/12/17.
//

#ifndef STRANGERSHIPS_ENTITYVIEW_H
#define STRANGERSHIPS_ENTITYVIEW_H


#include "View.h"
#include "../firstAid/Transformation.h"

#include <utility>

class EntityView : public Observer {
public:

    /*
     * Constructor
     */
    EntityView(const std::shared_ptr<sf::RenderWindow> &window,
               std::shared_ptr<ActiveEntity> _entityPtr, std::shared_ptr<sf::Sprite> _sprite)
            : Observer(_entityPtr), _window(window), _entityPtr(_entityPtr), _sprite(
                        std::move(_sprite)) {

        // initialize the position
        this->_sprite->setPosition(Transformation::transformWidth(_entityPtr->getLocation().x),
                                   Transformation::transformHeight(_entityPtr->getLocation().y));

    }

    /**
     * @brief initialises a sprite based on the given filename;
     * @param string path + filename
     */
    virtual void makeSprite(const std::string& file);

    /**
     * @brief virtual function for drawing objects onto the screen
     */
    virtual void draw();

    void update(std::string what) override ;




protected:
    std::shared_ptr<sf::RenderWindow> _window;
    std::shared_ptr<ActiveEntity> _entityPtr;
    std::shared_ptr<sf::Sprite> _sprite;





};


#endif //STRANGERSHIPS_ENTITYVIEW_H
