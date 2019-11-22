/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "Speed.hpp"

/**
 * @brief Construct a new Speed object
 *
 * @param value The value of the speed
 */
rtype::engine::component::Speed::Speed(const int &value) :
_value(value) {}

/**
 * @brief Get the Speed value
 *
 * @return The Speed value
 */
int rtype::engine::component::Speed::getValue() const
{ return _value; }

/**
 * @brief Set the Speed value
 *
 * @param value The new Speed value
 */
void rtype::engine::component::Speed::setValue(const int &value)
{ _value = value; }
