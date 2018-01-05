
#ifndef STRANGERSHIPS_OBSTACLEVIEW_H
#define STRANGERSHIPS_OBSTACLEVIEW_H


#include <iostream>
#include "EntityView.h"

class ObstacleView : public PassiveEntityView {

public:
    /**
     * @brief default constructor ObstacleView
     */
    ObstacleView(const std::shared_ptr<sf::RenderWindow>& window, const std::shared_ptr<PassiveEntity> &_entityPtr) :
            PassiveEntityView(window, _entityPtr) {


    }
};

class BorderObstacleView : public  ObstacleView {

public:

    BorderObstacleView(const std::shared_ptr<sf::RenderWindow>& window, const std::shared_ptr<PassiveEntity> &_entityPtr) :
            ObstacleView(window, _entityPtr) {

        if (this->_entityPtr->is_inversed()) this->makeSprite("../assets/top.png");
        else this->makeSprite("../assets/base.png");


        int x = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().x, _window->getSize().x));
        int y = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().y, _window->getSize().y));
        this->_sprite->setPosition(x, y);

    }
};

class SporadicObstacleView : public ObstacleView {

public:

    SporadicObstacleView(const std::shared_ptr<sf::RenderWindow>& window, const std::shared_ptr<PassiveEntity> &_entityPtr) :
            ObstacleView(window, _entityPtr) {

        this->makeSprite("../assets/horizontal_tube.png");


        int x = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().x, _window->getSize().x));
        int y = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().y, _window->getSize().y));
        this->_sprite->setPosition(x, y);

    }

};


#endif //STRANGERSHIPS_OBSTACLEVIEW_H
