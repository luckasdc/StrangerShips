
#ifndef STRANGERSHIPS_SINGLETONS_H
#define STRANGERSHIPS_SINGLETONS_H

#include <chrono>

/*
 * SINGLETON
 */

template <typename Type>
class Singleton
{
public:

    /**
     * @brief get a single instance of a singleton class
     */
    static Type& getInstance()
    {
        static Type instance;
        return instance;
    }

protected:
    Singleton() {}
    ~Singleton() {}

public:
    // disable copy constructors
    Singleton& operator=(Singleton const &) = delete;
    Singleton(Singleton const &) = delete;
};

/*
 * STOPWATCH
 */

class Stopwatch : public Singleton<Stopwatch> {

    // Stopwatch, inherits from the singleton pattern

public:

    /**
     * @brief starts the timer
     */
    void start();

    /**
     * @brief returns the amount of time passed since the beginning of
     * the timer (start()-function call)
     * @return long long int
     */
    long long int elapsedMilliSeconds() const;


private:
    friend class Singleton<Stopwatch>;
    Stopwatch() = default;

    std::chrono::high_resolution_clock clock;
    std::chrono::nanoseconds startTime = std::chrono::nanoseconds{0};

};

/*
 * TRANSFORMATION
 */

class Transformation : public Singleton<Transformation> {

    // Transformation, inherits from the singleton pattern

public:
    friend class Singleton<Transformation>;

    /**
     * @brief transform the width of the given floats
     * @param original
     * @param screen
     * @return  float
     */
    static float transformWidth(float original, float screen);

    /**
     * @brief transform the height of the given floats
     * @param original
     * @param screen
     * @return float
     */
    static float transformHeight(float original, float screen);

};

#endif //STRANGERSHIPS_SINGLETONS_H
