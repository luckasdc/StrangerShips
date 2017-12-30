//
// Created by Luckas Declerck on 1/12/17.
//

#include <iostream>
#include "Transformation.h"

float Transformation::transformWidth(float original) {

    // check if original doesn't exceed borders
    if (original < -4 or original > 4) std::cerr<< "Width exceeds exceeds limits!" << std::endl;

    // map to range of canvas size
    float OldRange = (4 - (-4));
    float NewRange = (1000 - 0);
    float newvalue = (((original - (-4)) * NewRange) / OldRange) + 0;

    // assert if newvalue doenst exceed borders
    if (newvalue < 0 or newvalue > 1000) std::cerr<< "ASSERTION FAILED. New width exceeds limits!" << std::endl;

    return newvalue;

}

float Transformation::transformHeight(float original){

    // check if original doesn't exceed borders
    if (original < -3 or original > 3) std::cerr<< "Width exceeds exceeds limits!" << std::endl;

    // map to range of canvas size
    float OldRange = (3 - (-3));
    float NewRange = (750 - 0);
    float newvalue = (((original - (-3)) * NewRange) / OldRange) + 0;

    // assert if newvalue doenst exceed borders
    if (newvalue < 0 or newvalue > 750) std::cerr<< "ASSERTION FAILED. New width exceeds limits!" << std::endl;

    return newvalue;

}