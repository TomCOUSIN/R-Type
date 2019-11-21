/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <criterion/criterion.h>
#include "Position.hpp"

using namespace rtype::engine::component;

/**
 * @brief Test a basic creation of a Position component without parameters
 */
Test(component_position_tests, testing_creation_without_param)
{
    Position position;

    cr_assert_float_eq(position.getX(), 0.0f, 0);
    cr_assert_float_eq(position.getY(), 0.0f, 0);
}

/**
 * @brief Test a basic creation of a Position component with parameters
 */
Test(component_position_tests, testing_creation_with_params)
{
    Position position(5.0f, 6.0f);

    cr_assert_float_eq(position.getX(), 5.0f, 0);
    cr_assert_float_eq(position.getY(), 6.0f, 0);
}

/**
 * @brief Test to set x value of a position
 */
Test(component_position_tests, testing_x_setter)
{
    Position position;

    position.setX(3.0f);
    cr_assert_float_eq(position.getX(), 3.0f, 0);
}

/**
 * @brief Test to set y value of a position
 */
Test(component_position_tests, testing_y_setter)
{
    Position position;

    position.setY(3.0f);
    cr_assert_float_eq(position.getY(), 3.0f, 0);
}
