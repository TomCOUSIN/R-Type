/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "BulletSystem.hpp"
#include "FireEvent.hpp"

rtype::sfml::system::BulletSystem::BulletSystem(rtype::engine::GameEngine &engine) :
_engine(engine)
{}

void rtype::sfml::system::BulletSystem::update(float const &delta)
{
    engine::component::ComponentStorage position_store;
    engine::component::ComponentStorage speed_store;
    std::shared_ptr<engine::component::Position> position = nullptr;
    std::shared_ptr<engine::component::Speed> speed = nullptr;
    size_t count = 0;

    position_store = _engine.getComponentStorage<engine::component::Position>();
    speed_store = _engine.getComponentStorage<engine::component::Speed>();
    for (auto &entity : _entities) {
        position = position_store.getComponent<engine::component::Position>(entity);
        speed = speed_store.getComponent<engine::component::Speed>(entity);
        if (position && speed) {
            position->x += speed->x;
            if (position->x >= 1920) {
                _engine.destroyEntity(entity);
                return;
            }
        }
        ++count;
    }
}

void rtype::sfml::system::BulletSystem::addEntity(const rtype::engine::entity::Entity &entity)
{
    _entities.emplace_back(entity);
}

void rtype::sfml::system::BulletSystem::removeEntity(const rtype::engine::entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}
