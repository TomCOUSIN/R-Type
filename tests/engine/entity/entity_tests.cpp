/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <criterion/criterion.h>
#include "Entity.hpp"

using namespace rtype::engine::entity;

/**
 * @brief Tests the creation of an Entity object
 */
Test(entity_tests, testing_creation)
{
    Entity entity(1);

    cr_assert_eq(entity.getUniqueId(), 1);
}

/**
 * @brief Tests the setter of an Entity object
 */
Test(entity_tests, testing_setter)
{
    Entity entity(1);

    entity.setUniqueId(2);
    cr_assert_eq(entity.getUniqueId(), 2);
}
