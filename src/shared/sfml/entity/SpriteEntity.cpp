/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "AnimationSystem.hpp"
#include "PositionSystem.hpp"
#include "SpriteEntity.hpp"
#include "RenderSystem.hpp"
#include "EnemySystem.hpp"
#include "InputEvent.hpp"
#include "FireEvent.hpp"
#include "Position.hpp"
#include "Sprite.hpp"

const rtype::engine::entity::EntityType rtype::sfml::entity::SpriteEntity::type = 1 << engine::entity::ENTITY_TYPE::SPRITE;

rtype::sfml::entity::SpriteEntity::SpriteEntity(engine::GameEngine &engine,
    std::string const &texture_path, float const &x, float const &y,
    float const &width, float const &height, float const &scale_width,
    float const &scale_height, size_t const &sprite_count, bool const &movable,
    float const &speed_x, float const &speed_y, bool const &can_fire)
        : engine::entity::EntityCreator(engine)
        , _position(std::make_shared<engine::component::Position>(x, y))
        , _speed(std::make_shared<engine::component::Speed>(speed_x, speed_y))
{
    _sprite_entity = engine.createEntity();

    engine.linkEntityWithComponent<sfml::component::Sprite>(_sprite_entity, texture_path, width, height, scale_width, scale_height, sprite_count, engine::component::CENTERED::ALL);
    engine.linkEntityWithComponent(_sprite_entity, engine::component::Position::type, _position);
    engine.linkEntityWithComponent(_sprite_entity, engine::component::Speed::type, _speed);
    engine.linkEntityWithSystem<sfml::system::PositionSystem>(_sprite_entity);
    engine.linkEntityWithSystem<sfml::system::RenderSystem>(_sprite_entity);

    if (sprite_count >= 2) {
        engine.linkEntityWithSystem<sfml::system::AnimationSystem>(_sprite_entity);
    }

    if (movable) {
        engine.subscribeTo(
            event::InputEvent(event::InputEvent::ARROW_UP),
            std::bind(&SpriteEntity::onArrowUpPressed, this, std::placeholders::_1)
        );

        engine.subscribeTo(
            event::InputEvent(event::InputEvent::ARROW_DOWN),
            std::bind(&SpriteEntity::onArrowDownPressed, this, std::placeholders::_1)
        );

        engine.subscribeTo(
            event::InputEvent(event::InputEvent::ARROW_RIGHT),
            std::bind(&SpriteEntity::onArrowRightPressed, this, std::placeholders::_1)
        );

        engine.subscribeTo(
            event::InputEvent(event::InputEvent::ARROW_LEFT),
            std::bind(&SpriteEntity::onArrowLeftPressed, this, std::placeholders::_1)
        );
    }

    if (can_fire) {
        engine.subscribeTo(
            event::InputEvent(event::InputEvent::SPACE),
            std::bind(&SpriteEntity::onFire, this, std::placeholders::_1)
        );
    }
}

void rtype::sfml::entity::SpriteEntity::onArrowUpPressed(engine::event::Event const &event)
{
    _position->y -= _speed->y;
}

void rtype::sfml::entity::SpriteEntity::onArrowDownPressed(const rtype::engine::event::Event &event)
{
    _position->y += _speed->y;
}

void rtype::sfml::entity::SpriteEntity::onArrowRightPressed(const rtype::engine::event::Event &event)
{
    _position->x += _speed->x;
}

void rtype::sfml::entity::SpriteEntity::onArrowLeftPressed(const rtype::engine::event::Event &event)
{
    _position->x -= _speed->x;
}

void rtype::sfml::entity::SpriteEntity::onFire(const rtype::engine::event::Event &event)
{
    _game_engine.dispatchEvent(engine::event::Event(engine::event::EVENT_SENDER::FIRE, game::event::FireEventType::ALLY, _position));
}

rtype::engine::entity::Entity rtype::sfml::entity::SpriteEntity::getSpriteEntity() const
{
    return _sprite_entity;
}
