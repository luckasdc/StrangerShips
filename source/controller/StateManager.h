
#ifndef STRANGERSHIPS_STATEMANAGER_H
#define STRANGERSHIPS_STATEMANAGER_H

#include <stack>
#include <memory>
#include "State.h"

class State;

class StateManager {

public:
    StateManager() = default;

    /**
     * @brief adds a new state to the main stack, will be the current one
     * @param newState
     * @param isReplacing
     */
    void pushState(std::unique_ptr<State> newState, bool isReplacing = true);

    /**
     * @brief you guessed it.. it pops the latest one. The state underneath it will use it.
     */
    void popState();

    /**
     * @brief handle updates in the upper state
     */
    void processStates();

    /**
     * @brief getter for the top of the stack
     * @return stateptr
     */
    std::unique_ptr<State> &getCurrentState();


private:
    std::stack<std::unique_ptr<State>> _states;
    std::unique_ptr<State> _newState;
    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;
};


#endif //STRANGERSHIPS_STATEMANAGER_H
