/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <iostream>
#include "GameEngine.hpp"

/**
 * @brief Main function for the r-type-client-program
 *
 * @return 0 if no error occurred
 */
int main(void)
{
    rtype::engine::GameEngine engine;

    engine.createEntity("Player");
    engine.destroyEntity("Player");
    return 0;
}
