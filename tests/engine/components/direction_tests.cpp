/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <criterion/criterion.h>
#include "Direction.hpp"

using namespace rtype::engine::component;

/*
 * @brief Test the creation of a Direction component with up parameter set as true
 */
Test(component_direction_tests, testing_creation_with_up_parameter)
{
    Direction direction(true, false, false, false);

    cr_assert(direction.getUp());
    cr_assert_not(direction.getDown());
    cr_assert_not(direction.getRight());
    cr_assert_not(direction.getLeft());
}

/*
 * @brief Test the creation of a Direction component with down parameter set as true
 */
Test(component_direction_tests, testing_creation_with_down_parameter)
{
    Direction direction(false, true, false, false);

    cr_assert_not(direction.getUp());
    cr_assert(direction.getDown());
    cr_assert_not(direction.getRight());
    cr_assert_not(direction.getLeft());
}

/*
 * @brief Test the creation of a Direction component with right parameter set as true
 */
Test(component_direction_tests, testing_creation_with_right_parameter)
{
    Direction direction(false, false, true, false);

    cr_assert_not(direction.getUp());
    cr_assert_not(direction.getDown());
    cr_assert(direction.getRight());
    cr_assert_not(direction.getLeft());
}

/*
 * @brief Test the creation of a Direction component with left parameter set as true
 */
Test(component_direction_tests, testing_creation_with_left_parameter)
{
    Direction direction(false, false, false, true);

    cr_assert_not(direction.getUp());
    cr_assert_not(direction.getDown());
    cr_assert_not(direction.getRight());
    cr_assert(direction.getLeft());
}

/*
 * @brief Test the creation of a Direction component with all parameters set as true
 */
Test(component_direction_tests, testing_creation_with_all_parameters)
{
    Direction direction(true, true, true, true);

    cr_assert(direction.getUp());
    cr_assert(direction.getDown());
    cr_assert(direction.getRight());
    cr_assert(direction.getLeft());
}

/*
 * @brief Test the creation of a Direction component without parameters
 */
Test(component_direction_tests, testing_creation_without_parameters)
{
    Direction direction;

    cr_assert_not(direction.getUp());
    cr_assert_not(direction.getDown());
    cr_assert_not(direction.getRight());
    cr_assert_not(direction.getLeft());
}

/*
 * @brief Test the up setter of a Direction component
 */
Test(component_direction_tests, testing_up_setter)
{
    Direction direction;

    direction.setUp(true);
    cr_assert(direction.getUp());
}

/*
 * @brief Test the down setter of a Direction component
 */
Test(component_direction_tests, testing_down_setter)
{
    Direction direction;

    direction.setDown(true);
    cr_assert(direction.getDown());
}

/*
 * @brief Test the right setter of a Direction component
 */
Test(component_direction_tests, testing_right_setter)
{
    Direction direction;

    direction.setRight(true);
    cr_assert(direction.getRight());
}

/*
 * @brief Test the left setter of a Direction component
 */
Test(component_direction_tests, testing_left_setter)
{
    Direction direction;

    direction.setLeft(true);
    cr_assert(direction.getLeft());
}
