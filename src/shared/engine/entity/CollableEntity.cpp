/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "CollableEntity.hpp"
#include "Position.hpp"
#include "Speed.hpp"
#include "Collision.hpp"

namespace rtype::engine::entity {

const EntityType CollableEntity::type = 1 << engine::entity::ENTITY_TYPE::COLLABLE_ENTITY;

CollableEntity::CollableEntity(engine::GameEngine &engine
                              , float const &x
                              , float const &y
                              , float const &width
                              , float const &height
                              , float const &speed_x
                              , float const &speed_y)
    : engine::entity::EntityCreator(engine)
    , _position(std::make_shared<engine::component::Position>(x, y))
    , _speed(std::make_shared<engine::component::Speed>(speed_x, speed_y))
{
    _collable_entity = engine.createEntity();

    engine.linkEntityWithComponent(_collable_entity, component::Position::type, _position);
    engine.linkEntityWithComponent(_collable_entity, component::Speed::type, _speed);
    engine.linkEntityWithComponent<component::Collision>(_collable_entity, width, height, CollableEntity::type);
}

Entity CollableEntity::getCollableEntity() const
{
    return _collable_entity;
}

}

