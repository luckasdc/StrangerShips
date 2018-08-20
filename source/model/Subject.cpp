
#include "Subject.h"
#include <iostream>
void Subject::attach(std::shared_ptr<Observer> observer) {
    this->_observers.push_back(std::move(observer));
}

void Subject::detach() {
    this->_observers = {};
}

void Subject::notify(std::string what) {
    for (auto& observer : this->_observers) {
        observer->update(what);
    }
}

void Observer::update(std::string what) {

    std::cout << "update! but this function must be overridden"
            "so no one can see this!" << std::endl;
}
