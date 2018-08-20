
#ifndef STRANGERSHIPS_OBSTACLE_H
#define STRANGERSHIPS_OBSTACLE_H

#include "Entity.h"

class Obstacle : public PassiveEntity{
public:
    /**
     * @brief the Obstacle constructor
     */
    Obstacle() = default;

    /**
     * @brief shifts an obstacle to the left with the given speed.
     * if the obstacle goes out of field, notify observers to destruct
     * and append a new obstacle to the list.
     */
    virtual void shiftLeft();

protected:
    float _speed{};
};

class BorderObstacle : public Obstacle {

public:

    /**
     * @brief constructs a Borderobstacle and initilizes the right parameters of the boxes
     * @param speed
     * @param _bottomLeftCorner
     * @param inversed
     */
    BorderObstacle(float speed, float xValueBottomRightCorner, bool inversed = false);

};

class SporadicObstacle : public Obstacle {
public:
    /**
     * @brief constructs a SporadicObstacle and initilizes the right parameters
     * @param speed
     * @param xValueBottomRightCorner
     */
    SporadicObstacle(float speed, float xValueBottomRightCorner);

    void shiftLeft() override;
};

#endif //STRANGERSHIPS_OBSTACLE_H
