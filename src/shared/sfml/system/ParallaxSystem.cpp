/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "ParallaxSystem.hpp"
#include "Position.hpp"
#include "Speed.hpp"

rtype::sfml::system::ParallaxSystem::ParallaxSystem(rtype::engine::GameEngine &engine) :
_engine(engine) {}

void rtype::sfml::system::ParallaxSystem::update(float const &delta)
{
    if (!_engine.hasComponentStorage<engine::component::Position>() &&
        !_engine.hasComponentStorage<engine::component::Speed>())
        return;
    auto position_store = _engine.getComponentStorage<engine::component::Position>();
    auto speed_store = _engine.getComponentStorage<engine::component::Speed>();
    std::shared_ptr<engine::component::Position> position = nullptr;
    std::shared_ptr<engine::component::Speed> speed = nullptr;

    for (auto &entity : _entities) {
        if (position_store.entityHasComponent(entity) && speed_store.entityHasComponent(entity)) {
            position = position_store.getComponent<engine::component::Position>(entity);
            speed = speed_store.getComponent<engine::component::Speed>(entity);
            if (position->x >= -1920) {
                position->x -= speed->x;
            } else {
                position->x = -1 * speed->x;
            }
        }
    }
}

void rtype::sfml::system::ParallaxSystem::addEntity(const rtype::engine::entity::Entity &entity)
{
    _entities.emplace_back(entity);
}

void rtype::sfml::system::ParallaxSystem::removeEntity(const rtype::engine::entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}
