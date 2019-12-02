/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "Shared.hpp"
#include "Game.hpp"
#include "Server.hpp"
#include "GameEngine.hpp"
#include "BoostNetwork.hpp"

using namespace rtype;

static bool parseArgument(int ac, char const **av, std::size_t &port)
{
    if (ac != 2) {
#ifdef DEBUG
        port = 8080;
        return true;
#else
        return false;
#endif
    }
    try {
        port = std::stoi(av[1]);
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}

/**
 * @brief Main function for the r-type-server program
 *
 * @return 0 if no error occurred
 */
int main(int ac, char const **av)
{
    network::BoostNetwork network;
    engine::GameEngine engine;
    server::Server server_network(network, engine);
    // game::Game game;
    std::size_t port;

    if (!parseArgument(ac, av, port)) {
        std::cout << av[0] << " port" << std::endl;
        return 84;
    }
    server_network.start(port);
    return 0;
}
