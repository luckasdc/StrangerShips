//
// Created by Luckas Declerck on 13/11/17.
//

#include "Ship.h"


/*
 * SHIP
 */
// Constructor


// Member Functions

// Move()
void Ship::move(Direction dir) {

    //TODO: diagonal directions (extra switch-statements?)

    switch (dir) {
        case Up : {
            float newYU {_location.y + _speed};
            if (newYU >= 3) _location.y = 3;
            else _location.y = newYU;
            break;
        }
        case Down : {
            float newYD {_location.y - _speed};
            if (newYD <= -3) _location.y = -3;
            else _location.y = newYD;
            break;
        }
        case Right : {
            float newXR {_location.x + _speed};
            if (newXR >= 4) _location.x = 4;
            else _location.x = newXR;
            break;
        }
        case Left : {
            float newXL {_location.x + _speed};
            if (newXL <= -4) _location.x = -4;
            else _location.x = newXL;
            break;
        }
    }

    this->notify("movement");
}






/*
 * FRIENDLY SHIP
 */



/*
 * ENEMY SHIP
 */