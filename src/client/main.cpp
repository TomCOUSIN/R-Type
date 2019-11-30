/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "GameEngine.hpp"
#include "InputSystem.hpp"
#include "RenderSystem.hpp"
#include "PositionSystem.hpp"
#include "InputEvent.hpp"
#include "Event.hpp"
#include "Text.hpp"
#include "Position.hpp"
#include "Sprite.hpp"

#include <SFML/Graphics.hpp>

using namespace rtype;

/**
 * @brief Main function for the r-type_client program
 *
 * @return 0 if no error occurred
 */
int main(void)
{
    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    auto engine = engine::GameEngine();

    engine.loadSystem<sfml::system::InputSystem>(engine, window);
    engine.loadSystem<sfml::system::RenderSystem>(engine, window);
    engine.loadSystem<sfml::system::PositionSystem>(engine);
    engine.loadComponentStorage<engine::component::Position>();
    engine.loadComponentStorage<sfml::component::Sprite>();

    auto element = engine.createEntity();
    engine.linkEntityWithComponent<engine::component::Position>(element, 0, 0);
    engine.linkEntityWithComponent<sfml::component::Sprite>(element, "assets/flappy.png", 321, 224);
    auto storage = engine.getComponentStorage<engine::component::Position>();
    auto component = storage.getComponent<engine::component::Position>(element);

    engine.subscribeTo(
        sfml::event::InputEvent(engine::event::EVENT_SENDER::MOUSE, sfml::event::InputEvent::MOUSE_MOVE),
        [&](engine::event::Event const &event) {
            auto data = event.getEventData<engine::component::Position>();
            component->y = data->y;
            component->x = data->x;
        }
    );

    engine.linkEntityWithSystem<sfml::system::PositionSystem>(element);
    engine.linkEntityWithSystem<sfml::system::RenderSystem>(element);

    while (window.isOpen()) {
        if (clock.getElapsedTime().asMicroseconds() > 10000) {
            engine.update(2);
            clock.restart();
        }
    }

    return 0;
}
