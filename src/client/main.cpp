/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "GameEngine.hpp"
#include "ButtonEntity.hpp"
#include "MouseEntity.hpp"
#include "InputSystem.hpp"
#include "ButtonSystem.hpp"
#include "RenderSystem.hpp"
#include "PositionSystem.hpp"
#include "CollisionSystem.hpp"

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
    engine.loadSystem<engine::system::CollisionSystem>(engine);

    auto mouse = sfml::entity::MouseEntity(engine);
    std::vector<std::shared_ptr<sfml::entity::ButtonEntity>> arr;

    for (size_t i = 10; i < 800; i += 100) {
        for (size_t j = 10; j < 600; j += 60) {
            arr.push_back(std::make_shared<sfml::entity::ButtonEntity>(engine, "test", i, j, 100, 50, []{}));
        }
    }

    while (window.isOpen()) {
        if (clock.getElapsedTime().asMicroseconds() > 10000) {
            engine.update(2);
            clock.restart();
        }
    }

    return 0;
}
