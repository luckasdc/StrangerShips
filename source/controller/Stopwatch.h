//
// Created by Luckas Declerck on 21/11/17.
//

#ifndef STRANGERSHIPS_STOPWATCH_H
#define STRANGERSHIPS_STOPWATCH_H


#include <chrono>

class Stopwatch {

    // Singleton pattern

public:

    // get single instance of Stopwatch
    static Stopwatch& getStopwatch();

    void start();

    long long int elapsedMilliSeconds() const;


private:
    Stopwatch() = default;
    //Stopwatch(const Stopwatch&) = delete;
    //Stopwatch& operator=(const Stopwatch&) = delete;

    std::chrono::high_resolution_clock clock;
    std::chrono::nanoseconds startTime = std::chrono::nanoseconds{0};

};


#endif //STRANGERSHIPS_STOPWATCH_H
