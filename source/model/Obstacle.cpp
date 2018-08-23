
#include "Obstacle.h"

/*
 *  Obstacle
 */

void Obstacle::shiftLeft() {

    this->_bottomRightCorner.x -= _speed;

    // if obstacle goes out of range, move it to the front
    if (this->_bottomRightCorner.x + this->_width < -4) {
        this->_bottomRightCorner.x = 4;
    }
    this->notify("shift");
}


/*
 * BorderObstacle
 */
BorderObstacle::BorderObstacle(float speed, float xValueBottomRightCorner, bool inversed) {
    this->_speed = speed;
    // calculate location of bottom left corner
    Location loc;
    loc.x = xValueBottomRightCorner;
    if (inversed) loc.y = -4;
    else loc.y = 3;

    this->_bottomRightCorner = loc;
    this->_inversed = inversed;

    this->_width = 2;
    this->_height = 0.76;
}


/*
 * SporadicObstacle
 */

SporadicObstacle::SporadicObstacle(float speed, float yValueBottomRightCorner) {
    this->_speed = speed;
    Location loc;
    loc.x = 5;
    loc.y = yValueBottomRightCorner; //TODO MOET TOP LEFT CORNER WORDEN

    // TODO The sf::IntRect class is a simple utility type that represents a rectangle. Its constructor takes the coordinates of the TOP LEFT CORNER, and the size of the rectangle.
    this->_bottomRightCorner = loc;

    this->_width = 2.15;
    this->_height = 0.35;
}

void SporadicObstacle::shiftLeft() {
    this->_bottomRightCorner.x -= _speed;

    // if obstacle goes out of range, move it to the front
    if (this->_bottomRightCorner.x + this->_width < -4) {
        this->notify("obstacleDestructed");

    }
    this->notify("shift");
}
