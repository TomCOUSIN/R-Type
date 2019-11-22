/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "MovementSystem.hpp"

/**
 * @brief Construct a new MovementSystem object
 *
 * @param position The list of the Position component
 * @param direction The list of the Direction component
 * @param speed The list of the Speed component
 */
rtype::engine::system::MovementSystem::MovementSystem(
    rtype::engine::component::ComponentManager<rtype::engine::component::Position> &position,
    rtype::engine::component::ComponentManager<rtype::engine::component::Direction> &direction,
    rtype::engine::component::ComponentManager<rtype::engine::component::Speed> &speed) :
    _position(position), _direction(direction), _speed(speed) {}

/**
 * @brief Update Position values if Entity has Direction and Speed component
 */
void rtype::engine::system::MovementSystem::update()
{
    for (auto &position: _position.getComponentList()) {
        if (_speed.isEntityHasComponent(position.first) && _direction.isEntityHasComponent(position.first)) {
            updatePosition(position.first, position.second);
        }

    }
}

/**
 * @brief Update the Position values according to the Direction and Speed values
 */
void rtype::engine::system::MovementSystem::updatePosition(unsigned long const &entity_id, component::Position &position)
{
    auto speed = _speed.getComponentById(entity_id).getValue();
    if (_direction.getComponentById(entity_id).getUp()) {
        position.setY(position.getY() - speed);
    }
    if (_direction.getComponentById(entity_id).getDown()) {
        position.setY(position.getY() + speed);
    }
    if (_direction.getComponentById(entity_id).getRight()) {
        position.setX(position.getX() + speed);
    }
    if (_direction.getComponentById(entity_id).getLeft()) {
        position.setX(position.getX() - speed);
    }
    _position.setComponentById(entity_id, position);
}
