/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "ParallaxSystem.hpp"
#include "PositionSystem.hpp"
#include "ParallaxEntity.hpp"
#include "RenderSystem.hpp"
#include "InputEvent.hpp"
#include "Sprite.hpp"
#include "Speed.hpp"

const rtype::engine::entity::EntityType rtype::sfml::entity::ParallaxEntity::type = 1 << engine::entity::ENTITY_TYPE::PARALLAX;

rtype::sfml::entity::ParallaxEntity::ParallaxEntity(
    rtype::engine::GameEngine &game_engine,
    std::string const &background_path,
    std::string const &foreground_path,
    float const &background_speed_x) :
engine::entity::EntityCreator(game_engine),
_background_position(std::make_shared<engine::component::Position>(0, 0)),
_foreground_position(std::make_shared<engine::component::Position>(0, 0)),
_background_speed(std::make_shared<engine::component::Speed>(background_speed_x, 0)),
_foreground_speed(std::make_shared<engine::component::Speed>(background_speed_x + 2, 0)),
_background_sprite(std::make_shared<component::Sprite>(background_path, 3840,1080)),
_foreground_sprite(std::make_shared<component::Sprite>(foreground_path, 3840,1080))
{
    _game_engine.loadComponentStorage<engine::component::Position>();
    _game_engine.loadComponentStorage<engine::component::Speed>();
    _game_engine.loadComponentStorage<component::Sprite>();

    auto background = _game_engine.createEntity();
    auto foreground = _game_engine.createEntity();
    _background_entity = background;
    _foreground_entity = foreground;

    _game_engine.linkEntityWithComponent(background, engine::component::Position::type, _background_position);
    _game_engine.linkEntityWithComponent(foreground, engine::component::Position::type, _foreground_position);
    _game_engine.linkEntityWithComponent(background, engine::component::Speed::type, _background_speed);
    _game_engine.linkEntityWithComponent(foreground, engine::component::Speed::type, _foreground_speed);
    _game_engine.linkEntityWithComponent(background, component::Sprite::type, _background_sprite);
    _game_engine.linkEntityWithComponent(foreground, component::Sprite::type, _foreground_sprite);

    _game_engine.linkEntityWithSystem<system::PositionSystem>(background);
    _game_engine.linkEntityWithSystem<system::PositionSystem>(foreground);
    _game_engine.linkEntityWithSystem<system::ParallaxSystem>(background);
    _game_engine.linkEntityWithSystem<system::ParallaxSystem>(foreground);
    _game_engine.linkEntityWithSystem<system::RenderSystem>(foreground);
    _game_engine.linkEntityWithSystem<system::RenderSystem>(background);
}

void rtype::sfml::entity::ParallaxEntity::destroyParallax()
{
    _game_engine.destroyEntity(_background_entity);
    _game_engine.destroyEntity(_foreground_entity);
}

rtype::engine::entity::Entity rtype::sfml::entity::ParallaxEntity::getBackgroundEntity() const
{
    return _background_entity;
}
