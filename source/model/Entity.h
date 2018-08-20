
#ifndef STRANGERSHIPS_ENTITY_H
#define STRANGERSHIPS_ENTITY_H

#include "Subject.h"

enum Direction { Up, Down, Left, Right, Idle };

struct Location {
    float x;
    float y;
};


class Entity : public Subject {

protected:
      Entity() = default;
     ~Entity() = default;
};


class ActiveEntity : public Entity {
public:
    ActiveEntity() = default;
    ~ActiveEntity() = default;

    /**
     * @brief returns the location of an object in [-3, 3] x [-4, 4] dimensions
     * @return a Location object (this->x = x-value; this->y = y-value
     */
    Location getLocation();

    /**
     * @brief returns double health, if health == 0 --> entity is dead/broken.
     * @return double health,
     */
    double getHealth();

    /**
     * @brief pure virtual function for movement
     * @return none
     */
    virtual void move(Direction dir) = 0;

    /**
     * @brief subtracts int from remaining life
     * @param int health,
     */
    void hit(int health);

protected:
    Location _location;
    float _speed;
    int _health;

};


class PassiveEntity : public Entity {
public:

    /**
     * @brief returns the bottom left corner of a passive entity.
     * @return Location
     */
    const Location &get_bottomRightCorner() const;

    float get_width() const;

    float get_height() const;

    /**
     * @brief returns if the obstacle is inversed (for generating te top bar)
     */
    bool is_inversed() const;

protected:
    Location _bottomRightCorner = {};
    float _width {};
    float _height {};
    bool _inversed = true;
};


#endif //STRANGERSHIPS_ENTITY_H
