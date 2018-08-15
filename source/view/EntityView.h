

#ifndef STRANGERSHIPS_ENTITYVIEW_H
#define STRANGERSHIPS_ENTITYVIEW_H

#include <SFML/Graphics.hpp>

#include "../model/Subject.h"
#include "../firstAid/Singletons.h"
#include "../model/World.h"
#include "../model/Entity.h"
#include "../model/Subject.h"

#include <utility>

class EntityView : public Observer {
public:

    /**
     * @brief the default constructor for an EntityView, will automatically be called with
     * the construction of an ActiveEntityView or a PassiveEntityView.
     * @param window
     * @param _entityPtr
     */
    EntityView(std::shared_ptr<GamePreferences> preferences, const std::shared_ptr<Entity> _entityPtr)
            : Observer(_entityPtr), _preferences(std::move(preferences)) {};

    /**
     * @brief initialises a sprite based on the given filename;
     * @param string path + filename
     */
    virtual void makeSprite(const std::string& file);

    /**
     * @brief virtual function for drawing objects onto the screen
     */
    virtual void draw();


protected:
    std::shared_ptr<GamePreferences> _preferences;
    std::shared_ptr<sf::Sprite> _sprite;
    std::unique_ptr<sf::Texture> _texture = nullptr;

};


class ActiveEntityView : public  EntityView {

public:
    /**
     * @brief Constructor for ActiveEntityView
     * @param window
     * @param entityPtr
     */
    ActiveEntityView(const std::shared_ptr <GamePreferences> &preferences, const std::shared_ptr <ActiveEntity> &entityPtr)
        : EntityView(preferences, entityPtr), _entityPtr(entityPtr) {};

    /**
     * @brief override the Observer function 'update'();
     * @param string what
     */
    void update(std::string what) override ;

    /**
     * @brief getter for entityPtr
     * @return shared_ptr<ActiveEntity>
     */
    const std::shared_ptr <ActiveEntity> &get_entityPtr() const;

protected:
    std::shared_ptr<ActiveEntity> _entityPtr;


};


class PassiveEntityView : public  EntityView {
public:
    /**
     * @brief the constructor for a PassiveEntity
     * @param window
     * @param entityPtr
     */
    PassiveEntityView(const std::shared_ptr<GamePreferences> &preferences, const std::shared_ptr <PassiveEntity> &entityPtr)
            : EntityView(preferences, entityPtr), _entityPtr(entityPtr) {
        this->_width = _entityPtr->get_width();
        this->_height = _entityPtr->get_height();
    };

    /**
     * @brief override the Observer function 'update'();
     * @param string what
     */
    void update(std::string what) override ;

    /**
     * @brief overrides orgininal -> initialises a sprite based on the given filename;
     * @param string path + filename
     */
    void makeSprite(const std::string& file) override;

    /**
     * @brief getter for entityPtr
     * @return shared_ptr<ActiveEntity>
     */
    const std::shared_ptr <PassiveEntity> &get_entityPtr() const;


protected:
    std::shared_ptr<PassiveEntity> _entityPtr;
    float _width {};
    float _height {};


};

#endif //STRANGERSHIPS_ENTITYVIEW_H
