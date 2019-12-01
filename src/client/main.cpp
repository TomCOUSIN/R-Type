/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <Game.hpp>

using namespace rtype;

/**
 * @brief Main function for the r-type_client program
 *
 * @return 0 if no error occurred
 */
int main(void)
{
    game::Game game;

    game.start();
    game.stop();
    return 0;
}
