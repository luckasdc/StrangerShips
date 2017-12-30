//
// Created by Luckas Declerck on 16/12/17.
//

#ifndef STRANGERSHIPS_SUBJECT_H
#define STRANGERSHIPS_SUBJECT_H


#include <memory>
#include <utility>
#include <string>

class Observer;

class Subject {
private:
    std::shared_ptr<Observer> _observer;

public:
    //Subject(std::shared_ptr<World> worldptr) : _worldPointer(std::move(worldptr)) {};
    Subject() = default;
    void attach(std::shared_ptr<Observer> observer);
    void detach(std::shared_ptr<Observer> observer);
    void notify(std::string what);



};

class Observer : public std::enable_shared_from_this<Observer>{
protected:
    std::shared_ptr<Subject> _subject;

public:
    Observer(std::shared_ptr<Subject> _subject) : _subject(std::move(_subject)) {

        // Since you cannot use share_from_this in a constructor (object itself hasn't been created yet,
        // so a weak ptr will be made), We need to solve this. Paul Houx has found a solution by using
        // Lamda Functions (https://forum.libcinder.org/topic/solution-calling-shared-from-this-in-the-constructor)
        auto wptr = std::shared_ptr<Observer>( this, [](Observer*){} );

        this->_subject->attach(shared_from_this());
    }

    virtual ~Observer() = default;

    virtual void update(std::string what) = 0;
};



#endif //STRANGERSHIPS_SUBJECT_H
