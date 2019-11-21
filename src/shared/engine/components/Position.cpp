/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "Position.hpp"

/**
 * @brief Construct a new Position object
 *
 * @param x The x value
 * @param y The y value
 */
rtype::engine::component::Position::Position(const float &x, const float &y) :
_x(x), _y(y) {}

/**
 * @brief Get the x value of the Position
 *
 * @return The x value
 */
float rtype::engine::component::Position::getX() const
{ return _x; }

/**
 * @brief Get the y value of the Position
 *
 * @return The y value
 */
float rtype::engine::component::Position::getY() const
{ return _y; }

/**
 * @brief Set the x value for the Position
 *
 * @param x The new x value
 */
void rtype::engine::component::Position::setX(const float &x)
{ _x = x; }

/**
 * @brief Set the y value for the Position
 *
 * @param x The new y value
 */
void rtype::engine::component::Position::setY(const float &y)
{ _y = y; }
