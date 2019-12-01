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
#include "BulletEntity.hpp"
#include "EnemyEntity.hpp"
#include "Sprite.hpp"

const rtype::engine::entity::EntityType rtype::sfml::entity::EnemyEntity::type = 1 << engine::entity::ENTITY_TYPE::ENEMY;

rtype::sfml::entity::EnemyEntity::EnemyEntity(rtype::engine::GameEngine &engine,
    std::string const &texture_path, float const &x, float const &y,
    float const &width, float const &height, float const &scale_width,
    float const &scale_height) :
rtype::engine::entity::EntityCreator(engine),
_position(std::make_shared<engine::component::Position>(x, y))
{
    _enemy_entity = engine.createEntity();

    engine.linkEntityWithComponent<sfml::component::Sprite>(
        _enemy_entity
        , texture_path
        , width
        , height
        , scale_width
        , scale_height
        , 1);
    engine.linkEntityWithComponent(_enemy_entity, engine::component::Position::type, _position);
    engine.linkEntityWithComponent<engine::component::Collision>(_enemy_entity, width, height, type);
    engine.linkEntityWithSystem<sfml::system::PositionSystem>(_enemy_entity);
    engine.linkEntityWithSystem<engine::system::CollisionSystem>(_enemy_entity);
    engine.linkEntityWithSystem<sfml::system::RenderSystem>(_enemy_entity);

    _game_engine.subscribeTo(
        engine::event::CollisionEvent(engine::event::CollisionEvent::BEGIN_COLLIDE, _enemy_entity, BulletEntity::type),
        std::bind(&EnemyEntity::onCollision, this, std::placeholders::_1)
    );
}

rtype::engine::entity::Entity rtype::sfml::entity::EnemyEntity::getEnemyEntity() const
{
    return _enemy_entity;
}

void rtype::sfml::entity::EnemyEntity::onCollision(const rtype::engine::event::Event &event)
{
    _game_engine.destroyEntity(_enemy_entity);
}
