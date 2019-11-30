/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "GameEngine.hpp"
#include "ButtonEntity.hpp"
#include "InputSystem.hpp"
#include "ButtonSystem.hpp"
#include "RenderSystem.hpp"
#include "PositionSystem.hpp"

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
    engine.loadSystem<sfml::system::ButtonSystem>(engine, window);
    engine.loadSystem<sfml::system::PositionSystem>(engine);

    auto button = sfml::entity::ButtonEntity(engine, "bonjour", 10, 10, 100, 50, []{});

    while (window.isOpen()) {
        if (clock.getElapsedTime().asMicroseconds() > 10000) {
            engine.update(2);
            clock.restart();
        }
    }

    return 0;
}
