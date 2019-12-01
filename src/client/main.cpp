/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "Shared.hpp"
#include "Game.hpp"
#include "ClientNetwork.hpp"
#include "BoostNetwork.hpp"

using namespace rtype;

static bool parseArgument(int ac, char const **av, std::string &username, std::string &ip, std::size_t &port)
{
    if (ac != 4) {
#ifdef DEBUG
        username = "lucas";
        ip = "127.0.0.1";
        port = 8080;
        return true;
#else
        return false;
#endif
    }
    username = std::string(av[1]);
    ip = std::string(av[2]);
    try {
        port = std::stoi(av[3]);
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}

/**
 * @brief Main function for the r-type_client program
 *
 * @return 0 if no error occurred
 */
int main(int ac, char const **av)
{
    network::BoostNetwork network;
    client::ClientNetwork client_network(network);
    game::Game game;
    std::size_t port;
    std::string ip;
    std::string username;

    if (!parseArgument(ac, av, username, ip, port)) {
        std::cout << av[0] << " username server_ip server_port" << std::endl;
        return 84;
    }
    client_network.connect(ip, port, username);
    client_network.createSession();
    game.start();
    game.stop();
    return 0;
}
