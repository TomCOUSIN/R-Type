/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "PositionSystem.hpp"
#include "Position.hpp"
#include "Sprite.hpp"

rtype::sfml::system::PositionSystem::PositionSystem(rtype::engine::GameEngine &engine) :
_engine(engine) {}

void rtype::sfml::system::PositionSystem::update(float const &delta)
{
    auto position_storage = _engine.getComponentStorage<component::Position>();
    auto sprite_storage = _engine.getComponentStorage<component::Sprite>();
    component::Position *position = nullptr;
    component::Sprite *sprite = nullptr;

    for (auto &entity : _entities) {
        if (position_storage.entityHasComponent(entity) && sprite_storage.entityHasComponent(entity)) {
            position = static_cast<component::Position *>(position_storage.getComponent(entity).get());
            sprite = static_cast<component::Sprite *>(sprite_storage.getComponent(entity).get());
            sprite->sprite.setPosition(position->value);
        }
    }
}

void rtype::sfml::system::PositionSystem::addEntity(const engine::entity::Entity &entity)
{
    _entities.push_back(entity);
}

void rtype::sfml::system::PositionSystem::removeEntity(const engine::entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}
