/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <Sprite.hpp>
#include "AnimationSystem.hpp"
#include "ComponentStorage.hpp"
#include "Component.hpp"
#include "Sprite.hpp"

rtype::sfml::system::AnimationSystem::AnimationSystem(engine::GameEngine &engine) :
_engine(engine) {}

void rtype::sfml::system::AnimationSystem::addEntity(const engine::entity::Entity &entity)
{
    _entities.push_back(entity);
}

void rtype::sfml::system::AnimationSystem::removeEntity(const rtype::engine::entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}

void rtype::sfml::system::AnimationSystem::update(float const &delta)
{
    if (!_engine.hasComponentStorage<component::Sprite>())
        return;
    auto sprite_store = _engine.getComponentStorage<component::Sprite>();
    component::Sprite *sprite = nullptr;

    for (auto &entity : _entities) {
        if (sprite_store.entityHasComponent(entity)) {
            sprite = static_cast<component::Sprite *>(sprite_store.getComponent(entity).get());
            sprite->next();
        }
    }
}
