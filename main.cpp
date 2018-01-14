
#include "source/controller/GameController.h"

int main()
{
    /*
     * ATTENTION: GAME IS MADE TO RUN AT THIS RESOLUTION. IT IS NOT ADVISED TO CHANGE
     * THIS PARAMETERS! 1200/900
     */
    Game game(1200, 900, "Stranger Ships");

    game.run();

    return 0;
} 