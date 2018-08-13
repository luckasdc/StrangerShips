//
// Created by Luckas Declerck on 9/08/18.
//

#ifndef STRANGERSHIPS_STATE_H
#define STRANGERSHIPS_STATE_H


#include "GameController.h"
#include "KeyController.h"
#include "CollisionController.h"
#include "AIController.h"

class GamePreferences;

class State {
public:
    virtual void Init() = 0;

    virtual void HandleInput() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    virtual void Pause() { }
    virtual void Resume() { }
};

class MenuState : public State {

public:

    explicit MenuState(std::shared_ptr<GamePreferences> preferences);

    void Init() override;
    void HandleInput() override;
    void Update() override;
    void Draw() override;

private:

    std::shared_ptr<GamePreferences> _preferences;
    std::shared_ptr<sf::Sprite> _BgSprite;
    std::shared_ptr<sf::Texture> _BgTexture;
    std::shared_ptr<sf::Sprite> _ButtonSprite;
    std::shared_ptr<sf::Texture> _ButtonTexture;
    std::shared_ptr<KeyController> _cctr;


};

class PlayingState : public State {

public:

    explicit PlayingState(std::shared_ptr<GamePreferences> preferences);

    void Init() override;
    void HandleInput() override;
    void Update() override;
    void Draw() override;

private:
    std::shared_ptr<GamePreferences> _preferences;
    std::shared_ptr<WorldView> _view;
    std::shared_ptr<World> _world;
    std::shared_ptr<CollisionController> cctr;
    std::shared_ptr<AIController> aictr;

};

class PausedState : public State {


};

class ScoresState : public State {

public:

    explicit ScoresState(std::shared_ptr<GamePreferences> preferences, int score);

    void Init() override;
    void HandleInput() override;
    void Update() override;
    void Draw() override;

private:

    std::shared_ptr<GamePreferences> _preferences;
    std::shared_ptr<sf::Sprite> _BgSprite;
    std::shared_ptr<sf::Texture> _BgTexture;

    std::shared_ptr<sf::Sprite> _GOTitle;
    std::shared_ptr<sf::Texture> _GOTitleTexture;
    std::shared_ptr<sf::Sprite> _GOContainer;
    std::shared_ptr<sf::Texture> _GOContainerTexture;
    std::shared_ptr<sf::Sprite> _retryButton;
    std::shared_ptr<sf::Texture> _retryButtonTexture;

    sf::Text _scoreText;
    int _score;

    sf::Font _font;

    std::shared_ptr<KeyController> _cctr;


};




#endif //STRANGERSHIPS_STATE_H
