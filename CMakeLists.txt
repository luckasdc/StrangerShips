cmake_minimum_required(VERSION 3.6)
project(StrangerShips)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp source/model/Entity.cpp source/model/Entity.h source/model/Bullet.cpp source/model/Bullet.h source/model/Obstacle.cpp source/model/Obstacle.h source/model/Ship.cpp source/model/Ship.h source/model/World.cpp source/model/World.h)
add_executable(StrangerShips ${SOURCE_FILES})