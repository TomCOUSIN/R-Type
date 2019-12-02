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
#include "SfmlGraphic.hpp"
#include "SfmlAudio.hpp"
#include "GameEngine.hpp"

using namespace rtype;

/**
 * @brief Main function for the r-type_client program
 *
 * @return 0 if no error occurred
 */
int main(int ac, char const **av)
{
    engine::GameEngine engine;
    network::BoostNetwork network;
    client::ClientNetwork client_network(network);
    sfml::graphic::SfmlGraphic graphic(engine);
    sfml::audio::SfmlAudio audio(engine);
    game::Game game(engine, graphic, audio, client_network, 30);

    game.start();
    game.stop();
    return 0;
}
