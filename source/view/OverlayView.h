//
// Created by Luckas Declerck on 3/01/18.
//

#ifndef STRANGERSHIPS_OVERLAYVIEW_H
#define STRANGERSHIPS_OVERLAYVIEW_H


#include <utility>

#include "EntityView.h"

class OverlayView {
public:
    /**
     * @brief default constructor for the OverlayView
     * @param _window
     * @param _world
     */
    OverlayView(std::shared_ptr<sf::RenderWindow> _window, std::shared_ptr<World> _world) : _window(std::move(
            _window)), _world(std::move(_world)) {
        initHeart();
    };

    /**
     * @brief draws the amount of hearts according to playership->getHealth
     */
    void drawLives();

    /**
    * @brief generates the right sprite for the hearts
    */
    void initHeart();


private:

    std::shared_ptr<sf::RenderWindow> _window;
    std::shared_ptr<World> _world;
    std::shared_ptr<sf::Sprite> _heartSprite;
    std::unique_ptr<sf::Texture> _heartTexture;



};


#endif //STRANGERSHIPS_OVERLAYVIEW_H
