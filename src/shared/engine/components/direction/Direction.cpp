/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "Direction.hpp"

/**
 * @brief Construct a new Direction object
 *
 * @param up The up boolean value
 * @param down The down boolean value
 * @param right The right boolean value
 * @param left The left boolean value
 */
rtype::engine::component::Direction::Direction(const bool &up, const bool &down, const bool &right, const bool &left) :
_up(up), _down(down), _right(right), _left(left) {}

/**
 * @brief Get the Direction up boolean
 *
 * @return The Direction up boolean
 */
bool rtype::engine::component::Direction::getUp() const
{ return _up; }

/**
 * @brief Get the Direction down boolean
 *
 * @return The Direction down boolean
 */
bool rtype::engine::component::Direction::getDown() const
{ return _down; }

/**
 * @brief Get the Direction right boolean
 *
 * @return The Direction right boolean
 */
bool rtype::engine::component::Direction::getRight() const
{ return _right; }

/**
 * @brief Get the Direction left boolean
 *
 * @return The Direction left boolean
 */
bool rtype::engine::component::Direction::getLeft() const
{ return _left; }

/**
 * @brief Set the Direction up boolean
 *
 * @param up The new Direction up boolean
 */
void rtype::engine::component::Direction::setUp(const bool &up)
{ _up = up; }

/**
 * @brief Set the Direction down boolean
 *
 * @param down The new Direction down boolean
 */
void rtype::engine::component::Direction::setDown(const bool &down)
{ _down = down; }

/**
 * @brief Set the Direction right boolean
 *
 * @param right The new Direction right boolean
 */
void rtype::engine::component::Direction::setRight(const bool &right)
{ _right = right; }

/**
 * @brief Set the Direction left boolean
 *
 * @param left The new Direction left boolean
 */
void rtype::engine::component::Direction::setLeft(const bool &left)
{ _left = left; }
