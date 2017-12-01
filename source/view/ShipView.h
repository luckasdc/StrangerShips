//
// Created by Luckas Declerck on 1/12/17.
//

#ifndef STRANGERSHIPS_SHIPVIEW_H
#define STRANGERSHIPS_SHIPVIEW_H


#include "View.h"

#include <utility>

class PlayerShipView : public View {
    /**
     * @brief default constructor of a ShipView
     * @param window
     * @param playerShip
     */
    PlayerShipView(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<PlayerShip> playerShip) :
            _playerShip(std::move(playerShip)),
            View(std::move(window)){};

    void draw () override;

private:

    std::shared_ptr<PlayerShip> _playerShip;
    std::shared_ptr<sf::Sprite> _sprite;

};



#endif //STRANGERSHIPS_SHIPVIEW_H
