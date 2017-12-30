//
// Created by Luckas Declerck on 29/11/17.
//

#ifndef STRANGERSHIPS_WorldView_H
#define STRANGERSHIPS_WorldView_H


#include "EntityView.h"


class WorldView : public Observer {

public:
// TODO add texture manager
    /**
     * @brief constructor for base-class View
     * @param window
     */
    WorldView(std::shared_ptr<World> world, std::shared_ptr<sf::RenderWindow> window)
            : Observer(world), _world(world), _window(std::move(window))  {}

    ~WorldView() override = default;




    /**
     * @brief  function for drawing objects onto the screen
     */
    void draw();


    void update(std::string what) override;



protected:
    std::shared_ptr<sf::RenderWindow> _window;
    std::shared_ptr<World> _world;
    std::vector<std::shared_ptr<EntityView> > _entityViews = {};

private:




};


#endif //STRANGERSHIPS_WorldView_H
