//
// Created by Luckas Declerck on 11/08/18.
//

#ifndef STRANGERSHIPS_STATEMANAGER_H
#define STRANGERSHIPS_STATEMANAGER_H

#include <stack>
#include <memory>
#include "State.h"

class State;

class StateManager {

public:

    StateManager() = default;

    void pushState(std::unique_ptr<State> newState, bool isReplacing = true);

    void popState();

    void processStates();

    std::unique_ptr<State> &getCurrentState();


private:

    std::stack<std::unique_ptr<State>> _states;
    std::unique_ptr<State> _newState;

    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;

};


#endif //STRANGERSHIPS_STATEMANAGER_H
