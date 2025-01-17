
#ifndef STRANGERSHIPS_SHIP_H
#define STRANGERSHIPS_SHIP_H

#include <tuple>
#include "Entity.h"

class Ship : public ActiveEntity {

public:

    /**
     * @brief a basic default constructor, since the real parameters will be set using
     * the constructors of PlayerShip and EnemyShip respectively
     */
    Ship() = default;

    /**
     * @brief default constructor
     */
     virtual ~Ship() = default;

    /**
     * @brief the function that moves a ship. It is the same function for playership
     * as well as enemyship.
     * @param dir
     */
    void move(Direction dir) override ;

    /**
     * @brief a pure virtual function that will be overridden in the playership and
     * enemyship class
     */
    virtual void shoot() = 0;
};


class World;


class PlayerShip : public Ship {

public:
    /**
     * @brief default constructor, initializes all the params in ShipView.cpp
     * using the given WorldPointer.
     */
    PlayerShip(World* myWorld);

    /**
     * @brief default constructor
     */
     ~PlayerShip() override = default;

    /**
     * @brief the shoot function, overridden by the virtual shoot function of
     * the Ship class. Will be called in the main game loop by the KeyController.
     */
    void shoot() override;

private:
    World* _myWorld;

};

class SecondPlayerShip : public PlayerShip {
public:

    /**
    * @brief Same as above, but has some different settings regarding the starting position.
    */
    SecondPlayerShip(World *myWorld);

    /**
     * @brief default destructor
     */
    ~SecondPlayerShip() override = default;

};


class World;


class EnemyShip : public Ship {
public:
    /**
     * @brief default constructor, initializes all the params in ShipView.cpp
     * using the given WorldPointer.
     */
    EnemyShip(World* myWorld);

    /**
     * @brief default destructor
     */
    ~EnemyShip() override = default;

    /**
     * @brief increments the bullet counter, and shoots a bullet in the right direction
     * when the bullet reaches an integer x (and will reset to 0 when shot).
     */
    void shoot() override ;

    /**
     * @brief everytime this function is called, it will increment the movecounter (this
     * limits the amound of random directions) and will move in the current direction.
     * After x function calls, a new direction will be chosen.
     */
    void moveRandomDirection();

    /**
     * @brief escape the bullet by escaping up or down
     */
    void escape();

protected:
    World* _myWorld;
    int _shotCounter;
    Direction _curdir;
    int _moveCounter;
    int _outOfRangecounter = 0;
};


class BossShip : public EnemyShip {
public:
    /**
    * @brief default constructor, initializes all the params in BossShipView.cpp
    * using the given WorldPointer.
    */
    BossShip(World* myWorld);

    /**
     * @brief default destructor
     */
    ~BossShip() override = default;

    /**
    * @brief increments the bullet counter, and shoots a bullet in the right direction
    * when the bullet reaches an integer x (and will reset to 0 when shot).
    */
    void shoot() override ;
};

#endif //STRANGERSHIPS_SHIP_H
