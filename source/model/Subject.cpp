//
// Created by Luckas Declerck on 16/12/17.
//

#include "Subject.h"
#include <iostream>
void Subject::attach(std::shared_ptr<Observer> observer) {
    this->_observer = std::move(observer);
}

void Subject::detach(std::shared_ptr<Observer> observer) {
    this->_observer = nullptr;
}

void Subject::notify(std::string what) {
    this->_observer->update(what);
}

void Observer::update(std::string what) {

    std::cout << "update!" << std::endl;

}
