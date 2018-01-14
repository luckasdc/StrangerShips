
#ifndef STRANGERSHIPS_SUBJECT_H
#define STRANGERSHIPS_SUBJECT_H


#include <memory>
#include <utility>
#include <string>
#include <vector>

class Observer;

class Subject {

public:
    Subject() = default;
    /**
     * @brief attaches the given observer to the subject (called by observer constructor)
     * @param observer
     */
    void attach(std::shared_ptr<Observer> observer);`

    /**
     * @brief detaches the observers
     */
    void detach();

    /**
     * @brief notifies the observer about what happened (strings)
     * @param what
     */
    void notify(std::string what);

private:
    std::vector<std::shared_ptr<Observer>> _observers ;


};

class Observer : public std::enable_shared_from_this<Observer>{
protected:
    std::shared_ptr<Subject> _subject;

public:
    /**
     * @brief an Observer constructor, will add the given subject to the observer
     * @param _subject
     */
    Observer(std::shared_ptr<Subject> _subject) : _subject(std::move(_subject)) {

        // Since you cannot use share_from_this in a constructor (object itself hasn't been created yet,
        // so a weak ptr will be made), We need to solve this. Paul Houx has found a solution by using
        // Lamda Functions (https://forum.libcinder.org/topic/solution-calling-shared-from-this-in-the-constructor)
        auto wptr = std::shared_ptr<Observer>( this, [](Observer*){} );

        this->_subject->attach(shared_from_this());
    }

    virtual ~Observer() = default;

    /**
     * @brief pure virtual update function
     * @param what
     */
    virtual void update(std::string what) = 0;
};



#endif //STRANGERSHIPS_SUBJECT_H
