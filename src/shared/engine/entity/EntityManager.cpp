/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "EntityManager.hpp"

/**
 * @brief Construct a new EntityManager object
 */
rtype::engine::entity::EntityManager::EntityManager() :
_id_counter(0), _entity_list(), _available_unique_id() {}

/**
 * @brief Create a new Entity object and gives it a unique_id
 *
 * @return A new Entity object with a valid unique_id
 */
rtype::engine::entity::Entity rtype::engine::entity::EntityManager::createNewEntity()
{
    if (!_available_unique_id.empty()) {
        unsigned long unique_id = _available_unique_id.back();
        _available_unique_id.pop_back();
        return _entity_list[unique_id];
    }
    else {
        _entity_list.emplace_back(Entity(generateUniqueId()));
        return _entity_list.back();
    }
}

/**
 * @brief Generate a new unique_id
 *
 * @return A new unique_id
 */
unsigned long rtype::engine::entity::EntityManager::generateUniqueId()
{ return _id_counter++; }

/**
 * @brief Remove an Entity from the list
 *
 * @param Id of the entity to remove
 * @return True on success / False on failure
 */
bool rtype::engine::entity::EntityManager::removeEntity(unsigned long entity_id)
{
    if (_entity_list.size() < entity_id) {
        return false;
    }
    else {
        _available_unique_id.emplace_back(entity_id);
        return true;
    }
}
