
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
    /*
     * ATTENTION: GAME IS BUILD TO RUN AT THIS RESOLUTION. IT IS NOT ADVISED TO CHANGE
     * THIS PARAMETERS!
     */
    Game game(1200, 900, "Stranger Ships");

    game.run();

    return 0;
}