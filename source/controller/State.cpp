//
// Created by Luckas Declerck on 9/08/18.
//

#include "State.h"
#include <utility>
#include "StateManager.h"

PlayingState::PlayingState(std::shared_ptr<GamePreferences> preferences) : _preferences(std::move(preferences)) {


}


void PlayingState::Init() {

    ////     CHANGE LEVEL HERE  (CLI)   ////

    // TODO hier moet het menu gelaunched worden
    // TODO current game file maken en opslagen

    // TODO LEVEL HARDCODED OP 1


    try {
        std::string level = "../Levels/level1.json"; // HARDCODE WEGHALEN TODO
        std::cout << "loading levelfile: " << level << "..." << std::endl;
        this->_world = std::make_shared<World> (level, this->_preferences->_multiplayer);  ////

    }
    catch (const std::exception& e){
        std::cerr << "This is not a valid Level file! Error given: " << e.what() << std::endl;
    }

    // TODO eigen exception class op basis van een exception tree


    // Load World and Parse Level:
    this->_view = std::make_shared<WorldView> (this->_world, this->_preferences->_window);
    this->_world->loadFromLevel();


    this->aictr = std::make_shared<AIController>(this->_world);
    this->cctr = std::make_shared<CollisionController>(this->_world);


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

    // Everything's ready for the next iteration!
    // clear the window with black color
    _preferences->_window->clear();

    // draw everything again...
    _view->draw();
    // and finally display the current frame!
    _preferences->_window->display();

}

// MENU STATE
MenuState::MenuState(std::shared_ptr<GamePreferences> preferences) : _preferences(std::move(preferences)){

}

void MenuState::Init() {

    _cctr = std::make_shared<KeyController>();
    // Set texture background
    this->_BgSprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture> texture(new sf::Texture);
    this->_ButtonSprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture> buttontexture(new sf::Texture);

    try {
        if (!texture->loadFromFile("../assets/bg.png",sf::IntRect(0, 0, _preferences->width, _preferences->height))){
            throw std::runtime_error("Could not load texture from file");
        }
        if (!buttontexture->loadFromFile("../assets/PlayButton.png")){
            throw std::runtime_error("Could not load texture from file");
        }
    }
    catch (std::runtime_error& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }

    // transfer ownership of texture to MenuState
    this->_BgTexture = std::move(texture);
    this->_BgSprite->setTexture(*this->_BgTexture);
    this->_ButtonTexture = std::move(buttontexture);
    this->_ButtonSprite->setTexture(*this->_ButtonTexture);

    _ButtonSprite->setPosition((_preferences->width / 2) - (_ButtonSprite->getGlobalBounds().width / 2), (_preferences->height / 2) - (_ButtonSprite->getGlobalBounds().height / 2));


}

void MenuState::HandleInput() {

    sf::Event event{};

    while (_preferences->_window->pollEvent(event)) {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed) {
            _preferences->_window->close();
        }
        // check if button has clicked
        if (_cctr->IsSpriteClicked(this->_ButtonSprite, sf::Mouse::Left, _preferences->_window)) {
            // Switch To Main Menu
            this->_preferences->stateManager->pushState(std::make_unique<PlayingState>(this->_preferences));


        }


    }
}

void MenuState::Update() {

}

void MenuState::Draw() {
    // Everything's ready for the next iteration!
    // clear the window with black color
    _preferences->_window->clear();

    _preferences->_window->draw(*_BgSprite);
    _preferences->_window->draw(*_ButtonSprite);

    // draw everything again...
    // and finally display the current frame!
    _preferences->_window->display();
}
