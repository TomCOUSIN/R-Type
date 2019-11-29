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
    engine.loadComponentStorage<sfml::component::Position>();
    engine.loadComponentStorage<sfml::component::Sprite>();

    auto element = engine.createEntity();
    engine.linkEntityWithComponent<sfml::component::Position>(element, 0, 0);
    engine.linkEntityWithComponent<sfml::component::Sprite>(element, "assets/flappy.png", 321, 224);
    auto storage = engine.getComponentStorage<sfml::component::Position>();
    auto component = static_cast<sfml::component::Position*>(storage.getComponent(element).get());

    engine.subscribeTo(
        sfml::event::InputEvent(engine::event::EVENT_SENDER::MOUSE, sfml::event::InputEvent::MOUSE_MOVE),
        [&](engine::event::Event const &event) {
            auto data = static_cast<sfml::component::Position*>(event.getEventData().get());
            component->value.y = data->value.y;
            component->value.x = data->value.x;
        }
    );

    engine.linkEntityWithSystem(element, sfml::system::PositionSystem::type);
    engine.linkEntityWithSystem(element, sfml::system::RenderSystem::type);

    while (window.isOpen()) {
        if (clock.getElapsedTime().asMicroseconds() > 10000) {
            engine.update(2);
            clock.restart();
        }
    }

    return 0;
}
