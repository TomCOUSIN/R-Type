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

#include <thread>

using namespace rtype::sfml::component;

rtype::sfml::system::PositionSystem::PositionSystem(engine::GameEngine &engine) :
_engine(engine) {
}

void rtype::sfml::system::PositionSystem::update(float const &delta)
{
    static auto &position_store = _engine.getComponentStorage<engine::component::Position>();

    for (auto &entity : _entities) {
        if (position_store.entityHasComponent(entity)) {
            auto position = position_store.getComponent<engine::component::Position>(entity);
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

void rtype::sfml::system::PositionSystem::updateSpritePosition(std::shared_ptr<engine::component::Position> position, const rtype::engine::entity::Entity &entity)
{
    static auto &sprite_store = _engine.getComponentStorage<component::Sprite>();

    if (sprite_store.entityHasComponent(entity)) {
        auto sprite = sprite_store.getComponent<component::Sprite>(entity);
        sprite->sprite.setPosition(sf::Vector2f(position->x, position->y));
    }
}

void rtype::sfml::system::PositionSystem::updateButtonPosition(std::shared_ptr<engine::component::Position> position, const rtype::engine::entity::Entity &entity)
{
    static auto &button_store = _engine.getComponentStorage<component::Button>();

    if (button_store.entityHasComponent(entity)) {
        auto button = button_store.getComponent<component::Button>(entity);
        button->shape.setPosition(sf::Vector2f(position->x, position->y));
    }
}

void rtype::sfml::system::PositionSystem::updateTextPosition(std::shared_ptr<engine::component::Position> position, const rtype::engine::entity::Entity &entity)
{
    static auto &text_store = _engine.getComponentStorage<component::Text>();

    if (text_store.entityHasComponent(entity)) {
        auto text = text_store.getComponent<component::Text>(entity);
        text->text.setPosition(sf::Vector2f(position->x, position->y));
    }
}
