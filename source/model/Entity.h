//
// Created by Luckas Declerck on 13/11/17.
//

#ifndef STRANGERSHIPS_ENTITY_H
#define STRANGERSHIPS_ENTITY_H

#include "Subject.h"

enum Direction { Up, Down, Left, Right };

struct Location {
    float x;
    float y;
};

class Entity : public Subject {

};




class ActiveEntity : public Entity {
public:


    /**
     * @brief returns the location of the entity.
     * @return  location,
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

protected:
    Location _location;
    float _speed;
    unsigned int _health;

};


class PassiveEntity : public Entity {
    
    
};

#endif //STRANGERSHIPS_ENTITY_H
