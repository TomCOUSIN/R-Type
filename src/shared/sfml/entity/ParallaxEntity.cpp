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

rtype::sfml::entity::ParallaxEntity::ParallaxEntity(
    rtype::engine::GameEngine &game_engine,
    std::string const &background_path,
    std::string const &foreground_path,
    float const &background_speed_x) :
engine::entity::EntityCreator(game_engine)
{
    _game_engine.loadComponentStorage<engine::component::Position>();
    _game_engine.loadComponentStorage<engine::component::Speed>();
    _game_engine.loadComponentStorage<component::Sprite>();

    auto background = _game_engine.createEntity();
    auto foreground = _game_engine.createEntity();

    _game_engine.linkEntityWithComponent<engine::component::Position>(background);
    _game_engine.linkEntityWithComponent<engine::component::Position>(foreground);
    _game_engine.linkEntityWithComponent<engine::component::Speed>(foreground, background_speed_x + 2);
    _game_engine.linkEntityWithComponent<engine::component::Speed>(background, background_speed_x);
    _game_engine.linkEntityWithComponent<component::Sprite>(background, background_path, 2400, 600);
    _game_engine.linkEntityWithComponent<component::Sprite>(foreground, foreground_path, 2400, 600);

    _game_engine.linkEntityWithSystem<system::PositionSystem>(background);
    _game_engine.linkEntityWithSystem<system::PositionSystem>(foreground);
    _game_engine.linkEntityWithSystem<system::ParallaxSystem>(background);
    _game_engine.linkEntityWithSystem<system::ParallaxSystem>(foreground);
    _game_engine.linkEntityWithSystem<system::RenderSystem>(background);
    _game_engine.linkEntityWithSystem<system::RenderSystem>(foreground);
}
