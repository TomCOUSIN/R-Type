/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <memory>
#include <criterion/criterion.h>
#include "ComponentStorage.hpp"
#include "Entity.hpp"

using namespace rtype::engine;

/**
 * @brief Test a basic Component insertion in the ComponentStorage
 */
Test(component_storage_tests, test_component_insertion)
{
    component::ComponentStorage<component::Component> storage;
    entity::Entity entity = 0;

    cr_assert(storage.addEntity(entity, std::make_shared<component::Component>()));
}

/**
 * @brief Test an invalid Component insertion in the ComponentStorage
 */
Test(component_storage_tests, test_invalid_component_insertion)
{
    component::ComponentStorage<component::Component> storage;
    entity::Entity entity = 0;

    storage.addEntity(entity, std::make_shared<component::Component>());
    cr_assert_not(storage.addEntity(entity, std::make_shared<component::Component>()));
}
