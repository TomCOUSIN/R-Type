/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "GameEngine.hpp"
#include "InputSystem.hpp"

/**
 * @brief Main function for the r-type_client program
 *
 * @return 0 if no error occurred
 */
int main(void)
{
    rtype::engine::GameEngine engine;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Clock clock;

    engine.loadSystem<InputSystem>(window);
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        engine.update(elapsed.asSeconds());
    }
    return 0;
}
