//
// Created by Luckas Declerck on 13/11/17.
//

#ifndef STRANGERSHIPS_ENTITY_H
#define STRANGERSHIPS_ENTITY_H

struct Location {
    float x;
    float y;
};

class Entity {

};




class ActiveEntity : public Entity {
public:
    Location getLocation();

protected:
    Location _location;

};


class PassiveEntity : public Entity {
    
    
};

#endif //STRANGERSHIPS_ENTITY_H
