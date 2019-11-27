/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "InputSystem.hpp"
#include "Event.hpp"

rtype::sfml::system::InputSystem::InputSystem(engine::GameEngine &engine, sf::RenderWindow &window) :
_engine(engine), _window(window) {}

void rtype::sfml::system::InputSystem::update(float const &delta)
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::KeyPressed) {
            switch(event.key.code) {
            case sf::Keyboard::Up: _engine.addEvent(engine::event::EVENT::ARROW_UP); break;
            case sf::Keyboard::Down: _engine.addEvent(engine::event::EVENT::ARROW_DOWN); break;
            case sf::Keyboard::Left: _engine.addEvent(engine::event::EVENT::ARROW_LEFT); break;
            case sf::Keyboard::Right: _engine.addEvent(engine::event::EVENT::ARROW_RIGHT); break;
            default: break;
            }
        }
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
