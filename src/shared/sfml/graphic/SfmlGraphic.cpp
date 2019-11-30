/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "AnimationSystem.hpp"
#include "MovementSystem.hpp"
#include "PositionSystem.hpp"
#include "ButtonSystem.hpp"
#include "RenderSystem.hpp"
#include "InputSystem.hpp"
#include "SfmlGraphic.hpp"
#include "Position.hpp"
#include "Button.hpp"
#include "Sprite.hpp"
#include "Speed.hpp"
#include "Text.hpp"

rtype::sfml::graphic::SfmlGraphic::SfmlGraphic(rtype::engine::GameEngine &engine) :
_engine(engine), _window(sf::VideoMode(1920, 1080), "Rtype") {}

void rtype::sfml::graphic::SfmlGraphic::init()
{
    _engine.loadSystem<sfml::system::InputSystem>(_engine, _window);
    _engine.loadSystem<sfml::system::RenderSystem>(_engine, _window);
    _engine.loadSystem<sfml::system::PositionSystem>(_engine);
    _engine.loadSystem<sfml::system::ButtonSystem>(_engine, _window);
    _engine.loadSystem<sfml::system::AnimationSystem>(_engine);
    _engine.loadSystem<sfml::system::MovementSystem>(_engine);
    _engine.loadComponentStorage<engine::component::Position>();
    _engine.loadComponentStorage<engine::component::Speed>();
    _engine.loadComponentStorage<sfml::component::Button>();
    _engine.loadComponentStorage<sfml::component::Sprite>();
    _engine.loadComponentStorage<sfml::component::Text>();
}

bool rtype::sfml::graphic::SfmlGraphic::isWindowOpen()
{
    return _window.isOpen();
}

void rtype::sfml::graphic::SfmlGraphic::update(float const &delta)
{
    _engine.update(delta);
}

rtype::engine::entity::Entity rtype::sfml::graphic::SfmlGraphic::createButton(
    float const &width, float const &height, void (*fptr)(void))
{
    engine::entity::Entity entity = _engine.createEntity();

    _engine.linkEntityWithComponent<sfml::component::Button>(entity, width, height, fptr);
    _engine.linkEntityWithSystem<sfml::system::ButtonSystem>(entity);
    return entity;
}

rtype::engine::entity::Entity rtype::sfml::graphic::SfmlGraphic::createText(
    std::string const &message)
{
    engine::entity::Entity entity = _engine.createEntity();

    _engine.linkEntityWithComponent<sfml::component::Text>(entity, message);
    return entity;
}

rtype::engine::entity::Entity rtype::sfml::graphic::SfmlGraphic::createSprite(
    std::string const &texture_path, float const &width, float const &height,
    const float &scale_width, const float &scale_height,
    const size_t &sprite_count)
{
    engine::entity::Entity entity = _engine.createEntity();

    _engine.linkEntityWithComponent<sfml::component::Sprite>(entity, texture_path,
        width, height, scale_width, scale_height, sprite_count);
    if (sprite_count >= 2)
        _engine.linkEntityWithSystem<sfml::system::AnimationSystem>(entity);
    return entity;
}

void rtype::sfml::graphic::SfmlGraphic::setPosition(
    const rtype::engine::entity::Entity &entity, float const &x_position,
    float const &y_position)
{
    _engine.linkEntityWithComponent<engine::component::Position>(x_position, y_position);
    _engine.linkEntityWithSystem<sfml::system::PositionSystem>(entity);
}

void rtype::sfml::graphic::SfmlGraphic::setVisible(
    const rtype::engine::entity::Entity &entity, bool visible)
{
    if (visible) {
        _engine.linkEntityWithSystem<sfml::system::RenderSystem>(entity);
    } else {
        _engine.unlinkEntityWithSystem<sfml::system::RenderSystem>(entity);
    }
}

void rtype::sfml::graphic::SfmlGraphic::setMovable(
    const rtype::engine::entity::Entity &entity, float const &x_speed,
    float const &y_value)
{
    _engine.linkEntityWithComponent<engine::component::Speed>(entity, x_speed, y_value);
    _engine.unlinkEntityWithSystem<sfml::system::MovementSystem>(entity);
}

void rtype::sfml::graphic::SfmlGraphic::removeElement(const rtype::engine::entity::Entity &entity)
{
    _engine.destroyEntity(entity);
}

