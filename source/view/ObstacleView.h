
#ifndef STRANGERSHIPS_OBSTACLEVIEW_H
#define STRANGERSHIPS_OBSTACLEVIEW_H

#include <iostream>
#include "EntityView.h"
#include "../controller/GameController.h"

class ObstacleView : public PassiveEntityView {

public:
    /**
     * @brief default constructor ObstacleView
     */
    ObstacleView(const std::shared_ptr<GamePreferences>& preferences, const std::shared_ptr<PassiveEntity> &_entityPtr) :
            PassiveEntityView(preferences, _entityPtr) {


    }
};

class BorderObstacleView : public  ObstacleView {

public:
    /**
     * @brief  constructor for a BorderObstacleView (loads assets)
     */
    BorderObstacleView(const std::shared_ptr<GamePreferences>& preferences, const std::shared_ptr<PassiveEntity> &_entityPtr) :
            ObstacleView(preferences, _entityPtr) {

        if (this->_entityPtr->is_inversed()) this->makeSprite("../assets/top.png");
        else this->makeSprite("../assets/base.png");


        int x = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().x, _preferences->_window->getSize().x));
        int y = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().y, _preferences->_window->getSize().y));
        this->_sprite->setPosition(x, y);

    }
};

class SporadicObstacleView : public ObstacleView {

public:
    /**
     * @brief  constructor for a SporadicObstacleView (loads assets)
     */
    SporadicObstacleView(const std::shared_ptr<GamePreferences>& preferences, const std::shared_ptr<PassiveEntity> &_entityPtr) :
            ObstacleView(preferences, _entityPtr) {

        this->makeSprite("../assets/horizontal_tube.png");


        int x = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().x, _preferences->_window->getSize().x));
        int y = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().y, _preferences->_window->getSize().y));
        this->_sprite->setPosition(x, y);

    }

};


#endif //STRANGERSHIPS_OBSTACLEVIEW_H
