
#include "StateManager.h"

void StateManager::pushState(std::unique_ptr<State> newState, bool isReplacing) {
    this->_isAdding = true;
    this->_isReplacing = isReplacing;
    this->_newState = std::move(newState);
}

void StateManager::popState() {
    this->_isRemoving = true;
}

void StateManager::processStates() {
    if (this->_isRemoving && !this->_states.empty()) {
        this->_states.pop();

        this->_isRemoving = false;
    }

    if (this->_isAdding) {
        if (!this->_states.empty()) {
            if (this->_isReplacing) {
                this->_states.pop();
            }
        }

        this->_states.push(std::move(this->_newState));
        this->_states.top()->Init();
        this->_isAdding = false;
    }
}


std::unique_ptr<State> &StateManager::getCurrentState() {
    return this->_states.top();
}

