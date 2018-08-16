//
// Created by Luckas Declerck on 9/08/18.
//

#include "State.h"
#include <utility>
#include "StateManager.h"
#include "../view/WorldView.h"
#include "GameController.h"
#include "../firstAid/Settings.h"


PlayingState::PlayingState(std::shared_ptr<GamePreferences> preferences) : _preferences(std::move(preferences)) {


}


void PlayingState::Init() {

    // TODO LEVEL HARDCODED OP 1

    try {
        std::string level = "../Levels/" + _preferences->_config->get_levels()[_preferences->currentLevel % _preferences->_config->get_levels().size()].file;
        std::cout << "loading levelfile: " << level << "..." << std::endl;
        this->_world = std::make_shared<World> (level, this->_preferences->_multiplayer, _preferences);  ////

    }
    catch (const std::exception& e){
        std::cerr << "This is not a valid Level file! Error given: " << e.what() << std::endl;
    }

    // TODO eigen exception class op basis van een exception tree


    // Load World and Parse Level:
    this->_view = std::make_shared<WorldView> (_world, _preferences);

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
    if (aictr->controlWaves()) {
        std::cout << "YOU SURVIVED THE LEVEL! " << std::endl;
        Highscore newscore;
        newscore.highscore = _world->getScore();
        newscore.name = _preferences->_config->get_username();
        _preferences->_config->append_score(newscore);
        _preferences->_config->save();
        _preferences->stateManager->popState();
        _preferences->stateManager->pushState(std::make_unique<ScoresState>(_preferences, _world->getScore(), true));
    }

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
        if (KeyController::getKeyController().IsSpriteClicked(this->_ButtonSprite, sf::Mouse::Left, _preferences->_window)) {
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



ScoresState::ScoresState(std::shared_ptr<GamePreferences> preferences, int score, bool won) : _preferences(std::move(preferences)), _score(score), _won(won) {

}

void ScoresState::Init() {

    // Set texture background
    this->_BgSprite = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture> texture(new sf::Texture);
    this->_GOTitle = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture> _GOTitleTexture(new sf::Texture);
    this->_GOContainer = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture> _GOContainerTexture(new sf::Texture);
    this->_retryButton = std::make_shared<sf::Sprite>();
    std::unique_ptr<sf::Texture> _retryButtonTexture(new sf::Texture);


    // TODO hardcode weghalen
    try {
        if (!texture->loadFromFile("../assets/bg.png",sf::IntRect(0, 0, _preferences->width, _preferences->height))){
            throw std::runtime_error("Could not load texture from file");
        }

        if (_won) {
            if (!_GOTitleTexture->loadFromFile("../assets/You-Won-Title.png")){
                throw std::runtime_error("Could not load texture from file");
            }
        } else {
            if (!_GOTitleTexture->loadFromFile("../assets/Game-Over-Title.png")){
                throw std::runtime_error("Could not load texture from file");
            }
        }

        if (!_GOContainerTexture->loadFromFile("../assets/Game-Over-Body.png")){
            throw std::runtime_error("Could not load texture from file");
        }
        if (!_retryButtonTexture->loadFromFile("../assets/PlayButton.png")){
            throw std::runtime_error("Could not load texture from file");
        }
    }
    catch (std::runtime_error& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }

    // transfer ownership of texture to MenuState
    this->_BgTexture = std::move(texture);
    this->_BgSprite->setTexture(*this->_BgTexture);
    this->_GOTitleTexture = std::move(_GOTitleTexture);
    this->_GOTitle->setTexture(*this->_GOTitleTexture);
    this->_GOContainerTexture = std::move(_GOContainerTexture);
    this->_GOContainer->setTexture(*this->_GOContainerTexture);
    this->_retryButtonTexture = std::move(_retryButtonTexture);
    this->_retryButton->setTexture(*this->_retryButtonTexture);

    _GOContainer->setPosition(sf::Vector2f((_preferences->width / 2) - (_GOContainer->getGlobalBounds().width / 2), (_preferences->height / 2) - (_GOContainer->getGlobalBounds().height / 2)));
    _GOTitle->setPosition(sf::Vector2f((_preferences->width / 3*2) - (_GOTitle->getGlobalBounds().width / 2), _GOContainer->getPosition().y - (_GOTitle->getGlobalBounds().height * 2)));
    _retryButton->setPosition(sf::Vector2f((_preferences->width / 2) - (_retryButton->getGlobalBounds().width / 2), _GOContainer->getPosition().y + _GOContainer->getGlobalBounds().height + (_retryButton->getGlobalBounds().height * 0.2)));

    std::string scoretext = "Your score is: \n \n" + std::to_string(_score);
    _font.loadFromFile("../assets/FlappyFont.ttf");
    _scoreText.setFont(_font);
    _scoreText.setString(scoretext);
    _scoreText.setCharacterSize(56);
    _scoreText.setColor(sf::Color::White);
    _scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
    _scoreText.setPosition(sf::Vector2f(_preferences->width / 3*2, _preferences->height / 2.20));

    std::string scores = "";

    for (auto& score : _preferences->_config->get_highscores()) {
        scores += score.name + "    " + std::to_string(score.highscore) + "\n";
    }

    _highscores.setFont(_font);
    _highscores.setString(scores);
    _highscores.setCharacterSize(45);
    _highscores.setColor(sf::Color::White);
    _highscores.setOrigin(sf::Vector2f(_highscores.getGlobalBounds().width / 2, _highscores.getGlobalBounds().height / 2));
    _highscores.setPosition(sf::Vector2f(_preferences->width / 10 * 2.2, _preferences->height / 2.7 ));

}

void ScoresState::HandleInput() {

    sf::Event event{};

    while (_preferences->_window->pollEvent(event)) {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed) {
            _preferences->_window->close();
        }
        // check if button has clicked
        if (KeyController::getKeyController().IsSpriteClicked(this->_retryButton, sf::Mouse::Left, _preferences->_window)) {
            // Switch To Main Menu
            if(_won) this->_preferences->currentLevel++;
            this->_preferences->stateManager->pushState(std::make_unique<PlayingState>(this->_preferences));

        }
    }
}

void ScoresState::Update() {

}

void ScoresState::Draw() {
    // Everything's ready for the next iteration!
    // clear the window with black color
    _preferences->_window->clear();

    _preferences->_window->draw(*_BgSprite);
    //_preferences->_window->draw(*_GOContainer);
    _preferences->_window->draw(*_GOTitle);
    _preferences->_window->draw(*_retryButton);
    _preferences->_window->draw(_highscores);
    _preferences->_window->draw(_scoreText);

    // draw everything again...
    // and finally display the current frame!
    _preferences->_window->display();
}
