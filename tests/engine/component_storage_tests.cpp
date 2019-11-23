/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <criterion/criterion.h>
#include "ComponentStorage.hpp"
#include "Position.hpp"
#include "Entity.hpp"

using namespace rtype::engine;

/**
 * @brief Test a basic Component insertion in the ComponentStorage
 */
Test(component_storage_tests, test_component_insertion)
{
    component::ComponentStorage<component::Position> storage;
    entity::Entity entity = 0;

    cr_assert(storage.addEntity(entity, component::Position()));
}

/**
 * @brief Test an invalid Component insertion in the ComponentStorage
 */
Test(component_storage_tests, test_invalid_component_insertion)
{
    component::ComponentStorage<component::Position> storage;
    entity::Entity entity = 0;

    storage.addEntity(entity, component::Position());
    cr_assert_not(storage.addEntity(entity, component::Position()));
}

/**
 * @brief Test to get the Component linked to an Entity
 */
Test(component_storage_tests, test_get_component)
{
    component::ComponentStorage<component::Position> storage;
    entity::Entity entity = 0;

    storage.addEntity(entity, component::Position());
    cr_assert_not_null(storage.getComponent(entity));
}

/**
 * @brief Test to get when the Entity isn't linked to a Component
 */
Test(component_storage_tests, test_invalid_get_component)
{
    component::ComponentStorage<component::Position> storage;
    entity::Entity entity = 0;

    cr_assert_null(storage.getComponent(entity));
}
