
#ifndef STRANGERSHIPS_STATE_H
#define STRANGERSHIPS_STATE_H

#include <SFML/Graphics.hpp>
#include "CollisionController.h"
#include "AIController.h"
#include "KeyController.h"
#include "../firstAid/Settings.h"


class WorldView;

class GamePreferences;

class State {

public:
    /**
     * @brief initalizes a given State, initiates values, parses files,... (pure virtual)
     */
    virtual void Init() = 0;

    /**
     * @brief handle key inputs and clicks (pure virtual)
     */
    virtual void HandleInput() = 0;

    /**
     * @brief recalculate stuff while playing (pure virtual)
     */
    virtual void Update() = 0;

    /**
     * @brief prints everything on the screen (pure virtual)
     */
    virtual void Draw() = 0;
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
    std::shared_ptr<KeyController>kctr;

};


class ScoresState : public State {

public:
    explicit ScoresState(std::shared_ptr<GamePreferences> preferences, int score, bool won);

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
    sf::Text _highscores;

    int _score;
    bool _won;

    sf::Font _font;
};


#endif //STRANGERSHIPS_STATE_H
