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
 * @brief Update Position values according to the Direction and Speed values
 */
void rtype::engine::system::MovementSystem::update()
{
    for (auto &position: _position.getComponentList()) {
        auto speed = _speed.getComponentById(position.first).getValue();
        if (_direction.getComponentById(position.first).getUp()) {
            position.second.setY(position.second.getY() - speed);
        }
        if (_direction.getComponentById(position.first).getDown()) {
            position.second.setY(position.second.getY() + speed);
        }
        if (_direction.getComponentById(position.first).getRight()) {
            position.second.setX(position.second.getX() + speed);
        }
        if (_direction.getComponentById(position.first).getLeft()) {
            position.second.setX(position.second.getX() - speed);
        }
        _position.setComponentById(position.first, position.second);
    }
}
