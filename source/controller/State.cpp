//
// Created by Luckas Declerck on 9/08/18.
//

#include "State.h"
#include <utility>

PlayingState::PlayingState(std::shared_ptr<GamePreferences> preferences) : _preferences(std::move(preferences)) {

    this->aictr = std::make_shared<AIController>(_world);
    this->cctr = std::make_shared<CollisionController>(_world);

}


void PlayingState::Init() {

    ////     CHANGE LEVEL HERE  (CLI)   ////

    // TODO hier moet het menu gelaunched worden
    // TODO current game file maken en opslagen

    // TODO LEVEL HARDCODED OP 1


    try {
        std::string level = "../Levels/level1.json"; // HARDCODE WEGHALEN TODO
        std::cout << "loading levelfile: " << level << "..." << std::endl;
        this->_world = std::make_shared<World> (level, _preferences->_multiplayer);  ////

    }
    catch (const std::exception& e){
        std::cerr << "This is not a valid Level file! Error given: " << e.what() << std::endl;
    }

    // TODO eigen exception class op basis van een exception tree


    // Load World and Parse Level:
    this->_view = std::make_shared<WorldView> (this->_world, this->_preferences->_window);
    this->_world->loadFromLevel();


}




void PlayingState::HandleInput() {

    sf::Event event{};

    while (_preferences->_window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed) {
            _preferences->_window->close();
        }
        // check if the player is shooting
        if (KeyController::getKeyController().processShooting(event, false)) _world->getPlayerShip()->shoot();

        // check if the second player is shooting
        if(_preferences->_multiplayer) {
            if (KeyController::getKeyController().processShooting(event, true)) _world->getSecondPlayerShip()->shoot();
        }

    }

    // check which keys are currently pressed to control movement (we cannot use events)

    Direction dir = KeyController::getKeyController().processDirection(false);
    Direction dir2 = KeyController::getKeyController().processDirection(true);

    if(dir != Idle) _world->getPlayerShip()->move(dir);
    if(dir2 != Idle && _preferences->_multiplayer) _world->getSecondPlayerShip()->move(dir2);


}

void PlayingState::Update() {

    // AI-controller: decides what the enemies are going to do
    aictr->makeDecisions();
    // AI-controller: launch a new wave and check if game is won
    aictr->controlWaves();
    // AI-controller: launch obstalces
    aictr->launchSporadicObstacle();

    // CollisionController: Check if there were any collisions and handle them
    cctr->updateBulletsAndObstacles();
    cctr->checkPlayerShip();

    // check which entities died during this iteration and remove the according views
    _world->updateEntities();

}

void PlayingState::Draw() {

    _preferences->_window->clear();

    _view->draw();

}



