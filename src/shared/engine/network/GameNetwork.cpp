/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include <string>

#include "GameNetwork.hpp"
#include "NetworkException.hpp"

namespace babel::network {

    GameNetwork::GameNetwork(INetwork &network, INetwork::packet_handlers_t handlers):
        network_(network),
        handlers_(handlers)
    {}

    void
    GameNetwork::onReceivePacket(Packet &packet)
    {
        INetwork::packet_callback_t handler;

        try {
            handler = _handlers.at(packet.getType());
        }
        catch (std::exception &e) {
            throw NetworkException(std::string("No handler found for '") + std::to_string(int(packet.getType())) + std::string("'. You must code it."));
        }
        try {
            handler(packet);
        }
        catch (std::exception &e) {
            throw NetworkException(e.what());
        }
    }

}
