//
// Created by Luckas Declerck on 21/11/17.
//

#include "Stopwatch.h"



void Stopwatch::start() {

    this->startTime = clock.now().time_since_epoch();

}

long long int Stopwatch::elapsedMilliSeconds() const {

    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto then = startTime;
    auto difference = std::chrono::duration_cast<std::chrono::milliseconds>(now - then);
    return difference.count();
}

Stopwatch &Stopwatch::getStopwatch() {
    // lazy initialization
    static auto *instance = new Stopwatch();
    return *instance;
}

