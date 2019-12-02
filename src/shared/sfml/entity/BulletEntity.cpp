/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "CollisionSystem.hpp"
#include "AnimationSystem.hpp"
#include "PositionSystem.hpp"
#include "CollisionEvent.hpp"
#include "RenderSystem.hpp"
#include "BulletSystem.hpp"
#include "BulletEntity.hpp"
#include "EnemyEntity.hpp"
#include "Sprite.hpp"

const rtype::engine::entity::EntityType rtype::sfml::entity::BulletEntity::type = 1 << engine::entity::ENTITY_TYPE::BULLET;

rtype::sfml::entity::BulletEntity::BulletEntity(
    rtype::engine::GameEngine &engine, std::string const &texture_path,
    float const &x, float const &y, float const &width, float const &height,
    float const &scale_width, float const &scale_height,
    size_t const &sprite_count, int const &direction) :
rtype::engine::entity::EntityCreator(engine),
_position(std::make_shared<engine::component::Position>(x, y)),
_speed(std::make_shared<engine::component::Speed>(10 * direction, 0))
{
    _bullet_entity = engine.createEntity();

    engine.linkEntityWithComponent<sfml::component::Sprite>(
        _bullet_entity
        , texture_path
        , width
        , height
        , scale_width
        , scale_height
        , sprite_count);
    engine.linkEntityWithComponent(_bullet_entity, engine::component::Position::type, _position);
    engine.linkEntityWithComponent(_bullet_entity, engine::component::Speed::type, _speed);
    engine.linkEntityWithComponent<engine::component::Collision>(_bullet_entity, width, height, type);
    engine.linkEntityWithSystem<sfml::system::PositionSystem>(_bullet_entity);
    engine.linkEntityWithSystem<sfml::system::BulletSystem>(_bullet_entity);
    engine.linkEntityWithSystem<sfml::system::RenderSystem>(_bullet_entity);
    engine.linkEntityWithSystem<sfml::system::AnimationSystem>(_bullet_entity);
}

rtype::engine::entity::Entity rtype::sfml::entity::BulletEntity::getBulletEntity() const
{
    return _bullet_entity;
}
