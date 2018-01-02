//
// Created by Luckas Declerck on 13/11/17.
//

#ifndef STRANGERSHIPS_ENTITY_H
#define STRANGERSHIPS_ENTITY_H

#include "Subject.h"

enum Direction { Up, Down, Left, Right, Idle };

struct Location {
    float x;
    float y;
};

class Entity : public Subject {

};




class ActiveEntity : public Entity {
public:


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
    unsigned int _health;

};


class PassiveEntity : public Entity {
    
    
};

#endif //STRANGERSHIPS_ENTITY_H
