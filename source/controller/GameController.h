
#ifndef STRANGERSHIPS_GAME_H
#define STRANGERSHIPS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../view/WorldView.h"
#include <memory>

class StateManager;

class GamePreferences {

public:

    GamePreferences();

    // TODO ombouwen tot Class met default value constructor en parser voor settings-file

    std::shared_ptr<sf::RenderWindow> _window;
    std::unique_ptr<StateManager> stateManager;
    bool _multiplayer = true;
    uint width = 1200;
    uint height = 900;

};

class Game {
public:

    /**
     * @brief a constructor for a new Game, creates an SFML window, creates a new world,
     * loads the level and creates a WorldView.
     * @param width
     * @param height
     * @param title
     */
    Game(uint width, uint height, std::string title, bool multiplayer);

    /**
     * @brief this function has the main Game loop and launches the game
     */
    void run ();



private:

    std::shared_ptr<GamePreferences> _preferences;


};


#endif //STRANGERSHIPS_GAME_H
