/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "MovementSystem.hpp"
#include "Position.hpp"
#include "Event.hpp"

rtype::sfml::system::MovementSystem::MovementSystem(rtype::engine::GameEngine &engine) :
_engine(engine) {}

void rtype::sfml::system::MovementSystem::update(float const &delta)
{
    auto position_store = _engine.getComponentStorage<component::Position>();
    auto speed_store = _engine.getComponentStorage<component::Speed>();
    component::Position *position = nullptr;
    component::Speed *speed = nullptr;
    auto events = _engine.getEvent();

    for (auto &entity : _entities) {
        if (position_store.entityHasComponent(entity) && speed_store.entityHasComponent(entity)) {
            position = static_cast<component::Position *>(position_store.getComponent(entity).get());
            speed = static_cast<component::Speed *>(speed_store.getComponent(entity).get());
            for (auto event : events) {
                switch(event) {
                case engine::event::ARROW_UP: moveUp(position, speed); break;
                case engine::event::ARROW_DOWN: moveDown(position, speed); break;
                case engine::event::ARROW_RIGHT: moveRight(position, speed); break;
                case engine::event::ARROW_LEFT: moveLeft(position, speed); break;
                    default: break;
                }
            }
        }
    }
}

void rtype::sfml::system::MovementSystem::addEntity(const rtype::engine::entity::Entity &entity)
{
    _entities.push_back(entity);
}

void rtype::sfml::system::MovementSystem::removeEntity(const rtype::engine::entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}

void rtype::sfml::system::MovementSystem::moveUp(component::Position *position, component::Speed *speed)
{
    position->value.y -= speed->speed;
}

void rtype::sfml::system::MovementSystem::moveDown(component::Position *position,  component::Speed *speed)
{
    position->value.y += speed->speed;
}

void rtype::sfml::system::MovementSystem::moveRight(component::Position *position, component::Speed *speed)
{
    position->value.x += speed->speed;
}

void rtype::sfml::system::MovementSystem::moveLeft(component::Position *position, component::Speed *speed)
{
    position->value.x -= speed->speed;
}
