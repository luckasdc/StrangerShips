
#include <iostream>

#include "source/controller/Game.h"

/**
 * main function, creates a game and starts it.
 *
 * @return  exit code
 */
int main()
{
    Game game (1920, 1080, "Stranger Ships");
    game.run();

    return 0;
}
