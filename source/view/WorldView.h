
#ifndef STRANGERSHIPS_WorldView_H
#define STRANGERSHIPS_WorldView_H


#include "EntityView.h"
#include "OverlayView.h"


class WorldView : public Observer {

public:
// TODO add texture manager
    /**
     * @brief constructor for WorldView object and initialize Background
     * + add an Overlay object to the WorldView and initialize it.
     * @param window
     */
    WorldView(const std::shared_ptr<World> &world, std::shared_ptr<sf::RenderWindow> window)
            : Observer(world), _world(world), _window(std::move(window))  {
        initBackground();
        _overlay = std::make_shared<OverlayView>(_window, _world);
        _overlay->initHeart();

    }

    ~WorldView() override = default;

    /**
     * @brief  function for drawing every entity of the world onto the screen
     * (as well as active/passive entities)
     */
    void draw();

    /**
     * @brief this function will be called when the subject notifies one of the following:
     *  -> the world created a new entity
     *  -> an entity died
     *  -> an entity went out of range
     * @param what
     */
    void update(std::string what) override;

    /**
     * @brief a function for initializing the background (not mandatory, is placed in the View
     * because it is not a part of the game logic. (= No entity)
     */
    void initBackground();



protected:
    std::shared_ptr<sf::RenderWindow> _window;
    std::shared_ptr<World> _world;
    std::vector<std::shared_ptr<ActiveEntityView> > _entityViews = {};
    std::vector<std::shared_ptr<PassiveEntityView> > _passiveEntityViews = {};
    std::shared_ptr<sf::Sprite> _BgSprite;
    std::unique_ptr<sf::Texture> _BgTexture;
    std::shared_ptr<OverlayView> _overlay;


};


#endif //STRANGERSHIPS_WorldView_H
