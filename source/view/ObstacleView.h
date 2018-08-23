
#ifndef STRANGERSHIPS_OBSTACLEVIEW_H
#define STRANGERSHIPS_OBSTACLEVIEW_H

#include <iostream>
#include "EntityView.h"

class ObstacleView : public PassiveEntityView {

public:
    /**
     * @brief default constructor ObstacleView
     */
    ObstacleView(const std::shared_ptr<GamePreferences>& preferences, const std::shared_ptr<PassiveEntity> &_entityPtr) :
            PassiveEntityView(preferences, _entityPtr) {
    }

    virtual ~ObstacleView() = default;
};


class BorderObstacleView : public  ObstacleView {

public:
    /**
     * @brief  constructor for a BorderObstacleView (loads assets)
     */
    BorderObstacleView(const std::shared_ptr<GamePreferences>& preferences, const std::shared_ptr<PassiveEntity> &_entityPtr);

     ~BorderObstacleView() override = default;
};



class SporadicObstacleView : public ObstacleView {

public:
    /**
     * @brief  constructor for a SporadicObstacleView (loads assets)
     */
    SporadicObstacleView(const std::shared_ptr<GamePreferences>& preferences, const std::shared_ptr<PassiveEntity> &_entityPtr);
    ~SporadicObstacleView() override = default;

};

#endif //STRANGERSHIPS_OBSTACLEVIEW_H
