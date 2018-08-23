
#include "source/controller/GameController.h"
#include "source/firstAid/Exception.h"

int main()
{
    try {
        Game game("../config.json");
        game.run();
    }
    catch (ex::Exception& what){
        std::cerr << "Gradius error: " << what.what() << std::endl;
    }
    catch (std::exception& what2) {
        std::cerr << "something went seriously wrong!" << std::endl;
    }
    return 0;
}  