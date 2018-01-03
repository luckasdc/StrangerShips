

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

        std::cout << _sprite->getPosition().x << ", " << _sprite->getPosition().y << std::endl;




    }


};


#endif //STRANGERSHIPS_OBSTACLEVIEW_H