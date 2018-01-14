
#include <iostream>
#include "../firstAid/Singletons.h"
#include "GameController.h"
#include "KeyController.h"
#include "CollisionController.h"
#include "AIController.h"

Game::Game(uint width, uint height, std::string title)
{
    this->_window = std::make_shared<sf::RenderWindow> (sf::VideoMode(width, height), "Stranger Ships");
    this->_window->create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    // Only one bullet can be shot at a time
    this->_window->setKeyRepeatEnabled(false);

    ////     CHANGE LEVEL HERE  (CLI)   ////

    std::cout << "Type the number of level you want to play: "
            "(level 1, 2 and 3 are ready to play)" << std::endl;
    std::string number = "";
    std::cin >> number;

    try {
        std::string level = "../Levels/level" + number + ".json";
        std::cout << "loading levelfile: " << level << "..." << std::endl;
        this->_world = std::make_shared<World> (level);  ////

    }
    catch (const std::exception& e){
        std::cerr << "This is not a valid Level file! Error given: " << e.what() << std::endl;
    }

    // Load World and Parse Level:
    this->_view = std::make_shared<WorldView> (this->_world, this->_window);
    this->_world->loadFromLevel();
}

void Game::run()
{
    Stopwatch::getInstance().start();
    CollisionController cctr (this->_world);
    AIController aictr (this->_world);

    sf::Event event{};

    while (this->_window->isOpen()) {

        // wait 'till the following amount of time has passed to maintain the right FPS
        if (Stopwatch::getInstance().elapsedMilliSeconds() < 16) {
            continue;
        }

        Stopwatch::getInstance ().start();


        // check all the window's events that were triggered since the last iteration of the loop
        while (_window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                _window->close();
            }
            // check if the player is shooting
            if (KeyController::getKeyController().processShooting(event)) _world->getPlayerShip()->shoot();

        }

        // check which keys are currently pressed to control movement (we cannot use events)
        Direction dir = KeyController::getKeyController().processDirection();
        if(dir != Idle) _world->getPlayerShip()->move(dir);

        // AI-controller: decides what the enemies are going to do
        aictr.makeDecisions();
        // AI-controller: launch a new wave and check if game is won
        aictr.controlWaves();
        // AI-controller: launch obstalces
        aictr.launchSporadicObstacle();

        // CollisionController: Check if there were any collions and handle them
        cctr.updateBulletsAndObstacles();
        cctr.checkPlayerShip();

        // check which entities died during this iteration and remove the according views
        _world->updateEntities();

        // Everything's ready for the next iteration!
        // clear the window with black color
        _window->clear();

        // draw everything again...
        _view->draw();

        // and finally display the current frame!
        _window->display();

    }


}
