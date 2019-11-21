/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "Entity.hpp"

/**
 * @brief Construct a new Entity object
 *
 * @param unique_id The unique_id of the new Entity
 */
rtype::engine::entity::Entity::Entity(const unsigned long &unique_id) :
_unique_id(unique_id) {}

/**
 * @brief Get the unique_id of the Entity
 *
 * @return The unique_id of the Entity
 */
unsigned long rtype::engine::entity::Entity::getUniqueId() const
{ return _unique_id; }

/**
 * @brief Set the unique_id of the Entity
 *
 * @param unique_id The new unique_id of the Entity
 */
void rtype::engine::entity::Entity::setUniqueId(const unsigned long &unique_id)
{ _unique_id = unique_id; }
