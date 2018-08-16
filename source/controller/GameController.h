
#ifndef STRANGERSHIPS_GAME_H
#define STRANGERSHIPS_GAME_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "../firstAid/Settings.h"

//forward declaration
class StateManager;

class GamePreferences {

public:

    GamePreferences(int width, int height);

    // TODO ombouwen tot Class met default value constructor en parser voor settings-file

    std::shared_ptr<sf::RenderWindow> _window;
    std::shared_ptr<StateManager> stateManager;
    bool _multiplayer = false;
    int width{};
    int height{};
    std::shared_ptr<Settings> _config;
    int currentLevel = 0;

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
    Game(const std::string& configfile);

    /**
     * @brief this function has the main Game loop and launches the game
     */
    void run ();



private:

    std::shared_ptr<GamePreferences> _preferences;
    std::shared_ptr<Settings> _config;

};


#endif //STRANGERSHIPS_GAME_H
