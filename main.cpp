
#include <iostream>

#include "source/controller/GameController.h"
#include "source/PrettyPrint.h"

/**
 * main function, creates a game and runs it.
 *
 * @return exit code
 */
int main()
{
    Game game(2000, 1500, "Stranger Ships");

    game.run();

    return 0;
}