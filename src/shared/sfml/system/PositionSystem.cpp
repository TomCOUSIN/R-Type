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
#include "Text.hpp"

using namespace rtype::sfml::component;

rtype::sfml::system::PositionSystem::PositionSystem(engine::GameEngine &engine) :
_engine(engine) {}

void rtype::sfml::system::PositionSystem::update(float const &delta)
{
    if (!_engine.hasComponentStorage<engine::component::Position>())
        return;
    auto position_store = _engine.getComponentStorage<engine::component::Position>();
    engine::component::Position *position;

    for (auto &entity : _entities) {
        if (position_store.entityHasComponent(entity)) {
            position = static_cast<engine::component::Position *>(position_store.getComponent(entity).get());
            if (_engine.hasComponentStorage<component::Sprite>())
                updateSpritePosition(position, entity);
            if (_engine.hasComponentStorage<component::Button>())
                updateButtonPosition(position, entity);
            if (_engine.hasComponentStorage<component::Text>())
                updateTextPosition(position, entity);
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

void rtype::sfml::system::PositionSystem::updateSpritePosition(engine::component::Position *position, const rtype::engine::entity::Entity &entity)
{
    auto sprite_store = _engine.getComponentStorage<component::Sprite>();
    component::Sprite *sprite = nullptr;

    if (sprite_store.entityHasComponent(entity)) {
        sprite = static_cast<component::Sprite *>(sprite_store.getComponent(entity).get());
        sprite->sprite.setPosition(sf::Vector2f(position->x, position->y));
    }
}

void rtype::sfml::system::PositionSystem::updateButtonPosition(engine::component::Position *position, const rtype::engine::entity::Entity &entity)
{
    auto button_store = _engine.getComponentStorage<component::Button>();
    component::Button *button = nullptr;

    if (button_store.entityHasComponent(entity)) {
        button = static_cast<component::Button *>(button_store.getComponent(entity).get());
        button->shape.setPosition(sf::Vector2f(position->x, position->y));
    }
}

void rtype::sfml::system::PositionSystem::updateTextPosition(engine::component::Position *position, const rtype::engine::entity::Entity &entity)
{
    auto text_store = _engine.getComponentStorage<component::Text>();
    component::Text *text = nullptr;

    if (text_store.entityHasComponent(entity)) {
        text = static_cast<component::Text *>(text_store.getComponent(entity).get());
        text->text.setPosition(sf::Vector2f(position->x, position->y));
    }
}
