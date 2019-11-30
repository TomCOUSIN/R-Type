/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "MovementSystem.hpp"
#include "Position.hpp"
#include "InputEvent.hpp"

namespace rtype::sfml::system {

MovementSystem::MovementSystem(rtype::engine::GameEngine &engine) :
_engine(engine) {}

void MovementSystem::update(float const &delta)
{
    if (!_engine.hasComponentStorage<engine::component::Position>() ||
        !_engine.hasComponentStorage<engine::component::Speed>())
        return;
    auto position_store = _engine.getComponentStorage<engine::component::Position>();
    auto speed_store = _engine.getComponentStorage<engine::component::Speed>();
    engine::component::Position *position = nullptr;
    engine::component::Speed *speed = nullptr;
    // auto events = _engine.getEvent();

    // for (auto &entity : _entities) {
    //     if (position_store.entityHasComponent(entity) && speed_store.entityHasComponent(entity)) {
    //         position = static_cast<component::Position *>(position_store.getComponent(entity).get());
    //         speed = static_cast<component::Speed *>(speed_store.getComponent(entity).get());
    //         for (const auto &event : events) {
    //             switch(event.getEventType()) {
    //             case event::InputEvent::ARROW_UP: moveUp(position, speed); break;
    //             case event::InputEvent::ARROW_DOWN: moveDown(position, speed); break;
    //             case event::InputEvent::ARROW_RIGHT: moveRight(position, speed); break;
    //             case event::InputEvent::ARROW_LEFT: moveLeft(position, speed); break;
    //                 default: break;
    //             }
    //         }
    //     }
    // }
}

void MovementSystem::addEntity(const rtype::engine::entity::Entity &entity)
{
    _entities.push_back(entity);
}

void MovementSystem::removeEntity(const rtype::engine::entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}

void MovementSystem::moveUp(std::shared_ptr<engine::component::Position> position, std::shared_ptr<engine::component::Speed> speed)
{
    position->y -= speed->y;
}

void MovementSystem::moveDown(std::shared_ptr<engine::component::Position> position,  std::shared_ptr<engine::component::Speed> speed)
{
    position->y += speed->y;
}

void MovementSystem::moveRight(std::shared_ptr<engine::component::Position> position, std::shared_ptr<engine::component::Speed> speed)
{
    position->x += speed->x;
}

void MovementSystem::moveLeft(std::shared_ptr<engine::component::Position> position, std::shared_ptr<engine::component::Speed> speed)
{
    position->x -= speed->x;
}

}
