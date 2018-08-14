
#include "source/controller/GameController.h"

int main()
{
    /*
     * ATTENTION: GAME IS MADE TO RUN AT THIS RESOLUTION. IT IS NOT ADVISED TO CHANGE
     * THIS PARAMETERS! 1200/900
     */


    try {
        Game game("../config.json");
        game.run();
    }

    catch (std::exception& what){
        std::cout << "das kapot é: " << what.what() << std::endl;
    }

    return 0;
}  