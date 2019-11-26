/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "InputSystem.hpp"

rtype::sfml::system::InputSystem::InputSystem(sf::RenderWindow &window) :
_window(window) {}

void rtype::sfml::system::InputSystem::update(float const &delta)
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
}

void rtype::sfml::system::InputSystem::addEntity(const engine::entity::Entity &entity)
{
    _entities.push_back(entity);
}

void rtype::sfml::system::InputSystem::removeEntity(const rtype::engine::entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}
