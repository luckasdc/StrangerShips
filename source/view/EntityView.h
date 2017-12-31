//
// Created by Luckas Declerck on 16/12/17.
//

#ifndef STRANGERSHIPS_ENTITYVIEW_H
#define STRANGERSHIPS_ENTITYVIEW_H

#include "SFML/Graphics.hpp"

#include "../model/Subject.h"
#include "../firstAid/Transformation.h"
#include "../model/World.h"
#include "../model/Entity.h"
#include "../model/Subject.h"

#include <utility>

class EntityView : public Observer {
public:

    /*
     * Constructor
     */
    EntityView(const std::shared_ptr<sf::RenderWindow> &window,
               std::shared_ptr<ActiveEntity> _entityPtr)
            : Observer(_entityPtr), _window(window), _entityPtr(_entityPtr) {

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

    /**
     * @brief getter for entityPtr
     * @return shared_ptr<ActiveEntity>
     */
    const std::shared_ptr <ActiveEntity> &get_entityPtr() const;


protected:
    std::shared_ptr<sf::RenderWindow> _window;
    std::shared_ptr<ActiveEntity> _entityPtr;
    std::shared_ptr<sf::Sprite> _sprite;
    std::unique_ptr<sf::Texture> _texture = nullptr;





};


#endif //STRANGERSHIPS_ENTITYVIEW_H
