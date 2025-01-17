
#include "Singletons.h"


void Stopwatch::start() {
    this->startTime = clock.now().time_since_epoch();
}

long long int Stopwatch::elapsedMilliSeconds() const {

    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto then = startTime;
    auto difference = std::chrono::duration_cast<std::chrono::milliseconds>(now - then);
    return difference.count();
}
/*
 * Transformation
 */
float Transformation::transformWidth(float original, float screen) {
    // check if original doesn't exceed borders
    float OldRange = (4 - (-4));
    float NewRange = (screen - 0);
    float newvalue = (((original - (-4)) * NewRange) / OldRange) + 0;

    return newvalue;
}

float Transformation::transformHeight(float original, float screen){
    // check if original doesn't exceed borders
    float OldRange = (3 - (-3));
    float NewRange = (screen - 0);
    float newvalue = (((original - (-3)) * NewRange) / OldRange) + 0;

    return newvalue;
}