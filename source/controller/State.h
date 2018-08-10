//
// Created by Luckas Declerck on 9/08/18.
//

#ifndef STRANGERSHIPS_STATE_H
#define STRANGERSHIPS_STATE_H


class State {
public:
    virtual void Init() = 0;

    virtual void HandleInput() = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw(float dt) = 0;

    virtual void Pause() { }
    virtual void Resume() { }
};



class PlayingState : public State {


};

class PausedState : public State {


};

class MenuState : public State {


};


#endif //STRANGERSHIPS_STATE_H
