
#include "ObstacleView.h"
#include "../controller/GameController.h"

BorderObstacleView::BorderObstacleView(const std::shared_ptr<GamePreferences> &preferences,
                                       const std::shared_ptr<PassiveEntity> &_entityPtr) :
        ObstacleView(preferences, _entityPtr) {

    if (this->_entityPtr->is_inversed()) this->makeSprite(_preferences->_config->get_texture_sky());
    else this->makeSprite(_preferences->_config->get_texture_floor());


    int x = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().x, _preferences->_window->getSize().x));
    int y = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().y, _preferences->_window->getSize().y));
    this->_sprite->setPosition(x, y);
}

SporadicObstacleView::SporadicObstacleView(const std::shared_ptr<GamePreferences> &preferences,
                                           const std::shared_ptr<PassiveEntity> &_entityPtr) : ObstacleView(preferences, _entityPtr) {

    this->makeSprite(_preferences->_config->get_texture_sporadicobstacle());

    int x = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().x, _preferences->_window->getSize().x));
    int y = static_cast<int>(Transformation::transformWidth(_entityPtr->get_bottomRightCorner().y, _preferences->_window->getSize().y));
    this->_sprite->setPosition(x, y);
}
