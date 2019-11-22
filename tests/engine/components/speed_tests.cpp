/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <criterion/criterion.h>
#include "Speed.hpp"

using namespace rtype::engine::component;

/**
 * @brief Test the creation of a Speed object with parameters
 */
Test(component_speed_tests, testing_creation_with_parameters)
{
    Speed speed(12);

    cr_assert_eq(speed.getValue(), 12);
}

/**
 * @brief Test the creation of a Speed object without parameters
 */
Test(component_speed_tests, testing_creation_without_parameters)
{
    Speed speed;

    cr_assert_eq(speed.getValue(), 1);
}

/**
 * @brief Test the setter of the Speed object
 */
Test(component_speed_tests, testing_setter)
{
    Speed speed;

    speed.setValue(23);
    cr_assert_eq(speed.getValue(), 23);
}
