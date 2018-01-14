cmake_minimum_required(VERSION 3.8)
project(StrangerShips)
set(CMAKE_CXX_STANDARD 11)

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics audio)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

set(SOURCE_FILES main.cpp source/model/Entity.cpp source/model/Entity.h source/model/Bullet.cpp source/model/Bullet.h source/model/Obstacle.cpp source/model/Obstacle.h source/model/Ship.cpp source/model/Ship.h source/model/World.cpp source/model/World.h source/controller/GameController.cpp source/controller/GameController.h source/view/WorldView.cpp source/view/WorldView.h source/view/ShipView.cpp source/view/ShipView.h source/view/EntityView.cpp source/view/EntityView.h source/model/Subject.cpp source/model/Subject.h source/controller/KeyController.cpp source/controller/KeyController.h source/controller/CollisionController.cpp source/controller/CollisionController.h source/view/BulletView.cpp source/view/BulletView.h source/controller/AIController.cpp source/controller/AIController.h source/view/ObstacleView.cpp source/view/ObstacleView.h source/view/OverlayView.cpp source/view/OverlayView.h source/firstAid/Level.cpp source/firstAid/Level.h source/firstAid/Singletons.cpp source/firstAid/Singletons.h)
add_executable(StrangerShips ${SOURCE_FILES})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(StrangerShips ${SFML_LIBRARIES})
