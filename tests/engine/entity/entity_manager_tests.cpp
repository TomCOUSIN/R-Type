/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <criterion/criterion.h>
#include "EntityManager.hpp"

using namespace rtype::engine::entity;

/**
 * @brief Test an Entity creation
 */
Test(entity_manager_tests, valid_entity_creation)
{
    EntityManager entity_manager;
    Entity entity = entity_manager.createNewEntity();

    cr_assert_eq(entity.getUniqueId(), 0);
}

/**
 * @brief Test multiple Entity creation
 */
Test(entity_manager_tests, valid_multiple_entity_creation)
{
    EntityManager entity_manager;
    Entity entity0 = entity_manager.createNewEntity();
    Entity entity1 = entity_manager.createNewEntity();
    Entity entity2 = entity_manager.createNewEntity();
    Entity entity3 = entity_manager.createNewEntity();
    Entity entity4 = entity_manager.createNewEntity();
    Entity entity5 = entity_manager.createNewEntity();

    cr_assert_eq(entity0.getUniqueId(), 0);
    cr_assert_eq(entity1.getUniqueId(), 1);
    cr_assert_eq(entity2.getUniqueId(), 2);
    cr_assert_eq(entity3.getUniqueId(), 3);
    cr_assert_eq(entity4.getUniqueId(), 4);
    cr_assert_eq(entity5.getUniqueId(), 5);
}

/**
 * @brief Test to remove an Entity
 */
Test(entity_manager_tests, remove_entity)
{
    EntityManager entity_manager;
    Entity entity0 = entity_manager.createNewEntity();
    Entity entity1 = entity_manager.createNewEntity();
    Entity entity2 = entity_manager.createNewEntity();
    Entity entity3 = entity_manager.createNewEntity();
    Entity entity4 = entity_manager.createNewEntity();
    Entity entity5 = entity_manager.createNewEntity();

    entity_manager.removeEntity(entity4.getUniqueId());
    cr_assert_eq(Entity(entity_manager.createNewEntity()).getUniqueId(), 4);
}

/**
 * @brief Test to remove multiple Entity
 */
Test(entity_manager_tests, remove_multiple_entity)
{
    EntityManager entity_manager;

    for (size_t index = 0; index < 10; ++index) {
        entity_manager.createNewEntity();
    }
    entity_manager.removeEntity(7);
    entity_manager.removeEntity(5);
    entity_manager.removeEntity(9);
    cr_assert_eq(Entity(entity_manager.createNewEntity()).getUniqueId(), 9);
    cr_assert_eq(Entity(entity_manager.createNewEntity()).getUniqueId(), 5);
    cr_assert_eq(Entity(entity_manager.createNewEntity()).getUniqueId(), 7);
}

/**
 * @brief Test if remove function return true on success
 */
Test(entity_manager_tests, valid_remove_entity)
{
    EntityManager entity_manager;

    entity_manager.createNewEntity();
    cr_assert(entity_manager.removeEntity(0));
}

/**
 * @brief Test if remove function return false on failure
 */
Test(entity_manager_tests, invalid_remove_entity)
{
    EntityManager entity_manager;

    entity_manager.createNewEntity();
    cr_assert_not(entity_manager.removeEntity(5));
}

