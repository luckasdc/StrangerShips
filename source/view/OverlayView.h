
#ifndef STRANGERSHIPS_OVERLAYVIEW_H
#define STRANGERSHIPS_OVERLAYVIEW_H


#include <utility>

#include "EntityView.h"

class OverlayView {
public:
    /**
     * @brief default constructor for the OverlayView
     * @param _preferences
     * @param _world
     */
    OverlayView(std::shared_ptr<GamePreferences>& preferences, std::shared_ptr<World> _world) : _preferences(preferences), _world(std::move(_world)) {
        initHeart();
        initScore();
        initLevelText();
        initLevelText();
    };

    /**
     * @brief draws the amount of hearts according to playership->getHealth
     */
    void drawLives();

    /**
     * @brief draws the score of the player on screen
     */
    void drawScore();

    /**
     * @brief draws the name of the current level
     */
     void drawLevel();

    /**
    * @brief generates the right sprite for the hearts
    */
    void initHeart();

    /**
    * @brief generates the text for the score
    */
    void initScore();

    /**
    * @brief generates the text for the current level
    */
    void initLevelText();

private:

    std::shared_ptr<GamePreferences> _preferences;
    std::shared_ptr<World> _world;
    std::shared_ptr<sf::Sprite> _heartSprite;
    std::unique_ptr<sf::Texture> _heartTexture;
    sf::Text _scoreText;
    sf::Text _levelText;
    sf::Font _font;



};


#endif //STRANGERSHIPS_OVERLAYVIEW_H
