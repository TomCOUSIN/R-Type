/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <criterion/criterion.h>
#include "ComponentManager.hpp"
#include "MovementSystem.hpp"
#include "EntityManager.hpp"

using namespace rtype::engine;

/**
 * @brief Test the MovementSystem object update function
 */
Test(movement_system_tests, first_testing_valid_update_function)
{
    component::ComponentManager<component::Position> position;
    component::ComponentManager<component::Direction> direction;
    component::ComponentManager<component::Speed> speed;
    system::MovementSystem system(position, direction, speed);
    entity::EntityManager manager;
    entity::Entity entity = manager.createNewEntity();

    position.addComponentToEntity(entity.getUniqueId(), component::Position(2.0f, 2.0f));
    direction.addComponentToEntity(entity.getUniqueId(), component::Direction(false, true, false, true));
    speed.addComponentToEntity(entity.getUniqueId(), component::Speed(2));
    system.update();
    cr_assert_float_eq(position.getComponentById(entity.getUniqueId()).getX(), 0.0f, 0.0f);
    cr_assert_float_eq(position.getComponentById(entity.getUniqueId()).getY(), 4.0f, 0.0f);
}

/**
 * @brief Test for a second time the MovementSystem object update function
 */
Test(movement_system_tests, second_testing_valid_update_function)
{
    component::ComponentManager<component::Position> position;
    component::ComponentManager<component::Direction> direction;
    component::ComponentManager<component::Speed> speed;
    system::MovementSystem system(position, direction, speed);
    entity::EntityManager manager;
    entity::Entity entity = manager.createNewEntity();

    position.addComponentToEntity(entity.getUniqueId(), component::Position(2.0f, 2.0f));
    direction.addComponentToEntity(entity.getUniqueId(), component::Direction(true, false, true, false));
    speed.addComponentToEntity(entity.getUniqueId(), component::Speed(2));
    system.update();
    cr_assert_float_eq(position.getComponentById(entity.getUniqueId()).getX(), 4.0f, 0.0f);
    cr_assert_float_eq(position.getComponentById(entity.getUniqueId()).getY(), 0.0f, 0.0f);
}

/**
 * @brief Test the MovementSystem object update function with multiple component
 */
Test(movement_system_tests, testing_valid_multiple_update_function)
{
    component::ComponentManager<component::Position> position;
    component::ComponentManager<component::Direction> direction;
    component::ComponentManager<component::Speed> speed;
    system::MovementSystem system(position, direction, speed);
    entity::EntityManager manager;
    entity::Entity entity1 = manager.createNewEntity();
    entity::Entity entity2 = manager.createNewEntity();

    position.addComponentToEntity(entity1.getUniqueId(), component::Position());
    direction.addComponentToEntity(entity1.getUniqueId(), component::Direction(false, false, true, false));
    speed.addComponentToEntity(entity1.getUniqueId(), component::Speed(2));
    position.addComponentToEntity(entity2.getUniqueId(), component::Position(10.0f, 10.0f));
    direction.addComponentToEntity(entity2.getUniqueId(), component::Direction(false, false, true, false));
    speed.addComponentToEntity(entity2.getUniqueId(), component::Speed(10));
    system.update();
    cr_assert_float_eq(position.getComponentById(entity1.getUniqueId()).getX(), 2.0f, 0.0f);
    cr_assert_float_eq(position.getComponentById(entity2.getUniqueId()).getX(), 20.0f, 0.0f);
}

// TODO Test invalid update function
