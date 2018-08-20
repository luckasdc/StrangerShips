
#ifndef STRANGERSHIPS_BULLETVIEW_H
#define STRANGERSHIPS_BULLETVIEW_H

#include "EntityView.h"

class BulletView : public ActiveEntityView {

public:
    /**
    * @brief default constructor of a BulletView
    * @param shared_ptr<window>
    * @param shared_ptr<Bullet>
    */
    BulletView(const std::shared_ptr<GamePreferences>& preferences, const std::shared_ptr<ActiveEntity> &_entityPtr);
};


#endif //STRANGERSHIPS_BULLETVIEW_H
