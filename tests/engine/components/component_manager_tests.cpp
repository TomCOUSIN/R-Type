/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <criterion/criterion.h>
#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "Position.hpp"

using namespace rtype::engine;

/**
 * @brief Test the link between an entity and a component
 */
Test(component_manager_tests, testing_link_entity_to_component)
{
    component::ComponentManager<component::Position> component_manager;
    entity::EntityManager entity_manager;
    component::Position position(5.0f, 12.0f);
    entity::Entity entity = entity_manager.createNewEntity();

    component_manager.addComponentToEntity(entity.getUniqueId(), position);
    cr_assert_eq(component_manager.getComponentList()[0].getX(), 5.0f);
    cr_assert_eq(component_manager.getComponentList()[0].getY(), 12.0f);
}

/**
 * @brief Test the valid return value of linking function
 */
Test(component_manager_tests, testing_valid_link_return_value)
{
    component::ComponentManager<component::Position> component_manager;
    entity::EntityManager entity_manager;
    component::Position position(5.0f, 12.0f);
    entity::Entity entity = entity_manager.createNewEntity();


    cr_assert(component_manager.addComponentToEntity(entity.getUniqueId(), position));
}

/**
 * @brief Test the invalid return value of linking function
 */
Test(component_manager_tests, testing_invalid_link_return_value)
{
    component::ComponentManager<component::Position> component_manager;
    entity::EntityManager entity_manager;
    component::Position position(5.0f, 12.0f);
    entity::Entity entity = entity_manager.createNewEntity();

    component_manager.addComponentToEntity(entity.getUniqueId(), position);
    cr_assert_not(component_manager.addComponentToEntity(entity.getUniqueId(), position));
}

/**
 * @brief Test to unlink entity
 */
Test(component_manager_tests, testing_unlink_entity)
{
    component::ComponentManager<component::Position> component_manager;
    entity::EntityManager entity_manager;
    component::Position position(5.0f, 12.0f);
    entity::Entity entity = entity_manager.createNewEntity();

    component_manager.addComponentToEntity(entity.getUniqueId(), position);
    component_manager.removeComponentByEntity(entity.getUniqueId());
    entity_manager.removeEntity(entity.getUniqueId());
    cr_assert(component_manager.getComponentList().empty());
}

/**
 * @brief Test the valid return value of unlink function
 */
Test(component_manager_tests, testing_valid_unlink_return_value)
{
    component::ComponentManager<component::Position> component_manager;
    entity::EntityManager entity_manager;
    component::Position position(5.0f, 12.0f);
    entity::Entity entity = entity_manager.createNewEntity();

    component_manager.addComponentToEntity(entity.getUniqueId(), position);
    cr_assert(component_manager.removeComponentByEntity(entity.getUniqueId()));
}

/**
 * @brief Test the invalid return value of unlink function
 */
Test(component_manager_tests, testing_invalid_unlink_return_value)
{
    component::ComponentManager<component::Position> component_manager;
    entity::EntityManager entity_manager;
    component::Position position(5.0f, 12.0f);
    entity::Entity entity = entity_manager.createNewEntity();

    component_manager.addComponentToEntity(entity.getUniqueId(), position);
    component_manager.removeComponentByEntity(entity.getUniqueId());
    cr_assert_not(component_manager.removeComponentByEntity(entity.getUniqueId()));
}

