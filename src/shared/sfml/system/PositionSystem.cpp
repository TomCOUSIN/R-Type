/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "PositionSystem.hpp"
#include "Position.hpp"
#include "Sprite.hpp"
#include "Button.hpp"

rtype::sfml::system::PositionSystem::PositionSystem(rtype::engine::GameEngine &engine) :
_engine(engine) {}

void rtype::sfml::system::PositionSystem::update(float const &delta)
{
    auto position_store = _engine.getComponentStorage<component::Position>();
    component::Position *position;

    for (auto &entity : _entities) {
        if (position_store.entityHasComponent(entity)) {
            position = static_cast<component::Position *>(position_store.getComponent(entity).get());
            updateSpritePosition(position, entity);
            updateButtonPosition(position, entity);
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

void rtype::sfml::system::PositionSystem::updateSpritePosition(component::Position *position, const rtype::engine::entity::Entity &entity)
{
    auto sprite_store = _engine.getComponentStorage<component::Sprite>();
    component::Sprite *sprite = nullptr;

    if (sprite_store.entityHasComponent(entity)) {
        sprite = static_cast<component::Sprite *>(sprite_store.getComponent(entity).get());
        sprite->sprite.setPosition(position->value);
    }
}

void rtype::sfml::system::PositionSystem::updateButtonPosition(component::Position *position, const rtype::engine::entity::Entity &entity)
{
    auto button_store = _engine.getComponentStorage<component::Button>();
    component::Button *button = nullptr;

    if (button_store.entityHasComponent(entity)) {
        button = static_cast<component::Button *>(button_store.getComponent(entity).get());
        button->shape.setPosition(position->value);
    }
}
