/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "InputSystem.hpp"
#include "Position.hpp"
#include "InputEvent.hpp"

using namespace rtype::sfml::system;

InputSystem::InputSystem(engine::GameEngine &engine, sf::RenderWindow &window) :
_engine(engine), _window(window) {}

void InputSystem::update(float const &delta)
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        switch(event.key.code) {
        case sf::Keyboard::Up: _engine.dispatchEvent(event::InputEvent(event::InputEvent::ARROW_UP)); break;
        case sf::Keyboard::Down: _engine.dispatchEvent(event::InputEvent(event::InputEvent::ARROW_DOWN)); break;
        case sf::Keyboard::Left: _engine.dispatchEvent(event::InputEvent(event::InputEvent::ARROW_LEFT)); break;
        case sf::Keyboard::Right: _engine.dispatchEvent(event::InputEvent(event::InputEvent::ARROW_RIGHT)); break;
        case sf::Keyboard::Space: _engine.dispatchEvent(event::InputEvent(event::InputEvent::SPACE)); break;
        default: break;
        }
        if (event.type == sf::Event::MouseMoved) {
            _engine.dispatchEvent(event::InputEvent(event::InputEvent::MOUSE_MOVED,
                std::make_shared<engine::component::Position>(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y)));
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            _engine.dispatchEvent(event::InputEvent(event::InputEvent::MOUSE_PRESSED,
                std::make_shared<engine::component::Position>(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y)));
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            _engine.dispatchEvent(event::InputEvent(event::InputEvent::MOUSE_RELEASED,
                std::make_shared<engine::component::Position>(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y)));
        }
    }
}

void InputSystem::addEntity(const engine::entity::Entity &entity)
{
    _entities.push_back(entity);
}

void InputSystem::removeEntity(const rtype::engine::entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}
