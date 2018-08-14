
#include "source/controller/GameController.h"

int main()
{

    try {
        Game game("../config.json");
        game.run();
    }

    catch (std::exception& what){
        std::cout << "das kapot é: " << what.what() << std::endl;
    }

    return 0;
}  