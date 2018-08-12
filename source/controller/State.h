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




#endif //STRANGERSHIPS_STATE_H
