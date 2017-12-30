
#include <iostream>

#include "source/controller/Game.h"
#include "source/PrettyPrint.h"

/**
 * main function, creates a game and starts it.
 *
 * @return  exit code
 */
int main()
{
    std::shared_ptr<Game> game = std::make_shared<Game>(1000, 750, "Stranger Ships");
    World newworld;


    std::shared_ptr<World> level1 = std::make_shared<World>();
    level1->checkIfInitialised();

    sf::Texture texture;
    texture.loadFromFile("../assets/plane.png");
    std::shared_ptr<sf::Sprite> psprite = std::make_shared<sf::Sprite>();
    psprite->setTexture(texture);


    std::shared_ptr<ActiveEntity> psentity = level1->get_playerShip();


    std::shared_ptr<PlayerShipView> ps = std::make_shared<PlayerShipView> (game->get_window(), psentity, psprite);
    psentity->attach(ps);

    std::cout << psentity->getLocation().x << ", " << psentity->getLocation().y << std::endl;
    psentity->move(Up);
    std::cout << psentity->getLocation().x << ", " << psentity->getLocation().y << std::endl;



    //game.run();

    /// OOLOLOOLLOLL/// 2e poging

    return 0;
}