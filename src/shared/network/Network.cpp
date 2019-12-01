/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include <string>

#include "Shared.hpp"
#include "Network.hpp"
#include "NetworkException.hpp"

namespace rtype::network {

    Network::Network(INetwork &network):
        _network(network),
        _handlers()
    {}

    Network::~Network(void)
    {
        _network.stop();
    }

    void
    Network::onReceivePacket(Packet &packet)
    {
        auto handler = _handlers.find(packet.getType());
        if (handler != _handlers.end()) {
            handler->second(packet);
        } else {
#ifdef DEBUG
            std::cout << "no handler found for " << packet.getType() << std::endl;
#endif
        }
    }

}
