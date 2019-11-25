/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "InputSystem.hpp"

rtype::engine::system::InputSystem::InputSystem(sf::Window &window) :
_window(window) {}

void rtype::engine::system::InputSystem::update(float const &delta)
{
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
}
