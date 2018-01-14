
#ifndef STRANGERSHIPS_GAME_H
#define STRANGERSHIPS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../view/WorldView.h"
#include <memory>

class Game {
public:

    /**
     * @brief a constructor for a new Game, creates an SFML window, creates a new world,
     * loads the level and creates a WorldView.
     * @param width
     * @param height
     * @param title
     */
    Game(uint width, uint height, std::string title);

    /**
     * @brief this function has the main Game loop and launches the game
     */
    void run ();


private:
    std::shared_ptr<sf::RenderWindow> _window;
    std::shared_ptr<WorldView> _view;
    std::shared_ptr<World> _world;

};


#endif //STRANGERSHIPS_GAME_H
