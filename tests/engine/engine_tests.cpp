/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <iostream>
#include <criterion/criterion.h>
#include "GameEngine.hpp"

using namespace rtype::engine;

/**
 * @brief Test the creation of an Entity with the engine
 */
Test(engine_tests, testing_entity_creation)
{
    rtype::engine::GameEngine engine;

    engine.createEntity("Player");
    cr_assert_eq(engine.getEntitys()["Player"], 0);
}

/**
 * @brief Test multiple Entity creation
 */
Test(engine_tests, testing_multiple_entity_creation)
{
    rtype::engine::GameEngine engine;

    engine.createEntity("Tom");
    engine.createEntity("Cousin");
    engine.createEntity("Lucas");
    engine.createEntity("Marandat");
    cr_assert_eq(engine.getEntitys()["Tom"], 0);
    cr_assert_eq(engine.getEntitys()["Cousin"], 1);
    cr_assert_eq(engine.getEntitys()["Lucas"], 2);
    cr_assert_eq(engine.getEntitys()["Marandat"], 3);
}

/**
 * @brief Test if the Entity is present in the array of GameEngine
 */
Test(engine_tests, testing_entity_in_engine)
{
    rtype::engine::GameEngine engine;

    engine.createEntity("Player");
    cr_assert_not(engine.getEntitys().empty());
}

/**
 * @brief Test the destruction of an Entity with the engine
 */
Test(engine_tests, testing_entity_destruction)
{
    rtype::engine::GameEngine engine;

    engine.createEntity("Player");
    engine.destroyEntity("Player");
    cr_assert(engine.getEntitys().empty());
}
