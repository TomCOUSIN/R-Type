/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "ButtonSystem.hpp"
#include "InputEvent.hpp"

namespace rtype::sfml::system {

ButtonSystem::ButtonSystem(rtype::engine::GameEngine &engine, sf::RenderWindow &window) :
_engine(engine), _window(window) {}

void ButtonSystem::update(float const &delta)
{
    if (!_engine.hasComponentStorage<rtype::engine::component::Position>() ||
        !_engine.hasComponentStorage<component::Button>())
        return;
    auto position_store = _engine.getComponentStorage<rtype::engine::component::Position>();
    auto button_store = _engine.getComponentStorage<component::Button>();
    rtype::engine::component::Position *position = nullptr;
    component::Button *button = nullptr;

    for (auto &entity : _entities) {
        if (button_store.entityHasComponent(entity) && position_store.entityHasComponent(entity)) {
            button = static_cast<component::Button *>(button_store.getComponent(entity).get());
            position = static_cast<rtype::engine::component::Position *>(position_store.getComponent(entity).get());
            checkButtonDisplay(button, position);
            checkButtonPressed(button, position);
        }
    }
}

void ButtonSystem::addEntity(const rtype::engine::entity::Entity &entity)
{
    _entities.push_back(entity);
}

void ButtonSystem::removeEntity(const rtype::engine::entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}

void ButtonSystem::checkButtonDisplay(component::Button *button, component::Position *button_position)
{
    sf::Vector2i mouse_position = sf::Mouse::getPosition(_window);
    bool x = false;
    bool y = false;

    if (mouse_position.x >= button_position->x && mouse_position.x <= button_position->x + button->size.x) {
        x = true;
    }
    if (mouse_position.y >= button_position->y && mouse_position.y <= button_position->y + button->size.y) {
        y = true;
    }
    if (x && y) {
        button->onHover();
    }
    else {
        button->onDisplay();
    }
}

void ButtonSystem::checkButtonPressed(component::Button *button, rtype::engine::component::Position *button_position)
{
    rtype::engine::component::Position *position = nullptr;
    bool x = false;
    bool y = false;

    // for (auto &event : _engine.getEvent()) {
    //     if (event.getEventType() == event::InputEvent::MOUSE_CLICK) {
    //         position = static_cast<component::Position *>(event.getEventData().get());
    //         if (position->value.x >= button_position->value.x && position->value.x <= button_position->value.x + button->size.x) {
    //             x = true;
    //         }
    //         if (position->value.y >= button_position->value.y && position->value.y <= button_position->value.y + button->size.y) {
    //             y = true;
    //         }
    //         if (x && y) {
    //             button->onClick();
    //         }
    //     }
    //     x = false;
    //     y = false;
    // }
}

}
