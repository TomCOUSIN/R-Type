/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include "ServerNetwork.hpp"
#include "GameNetwork.hpp"

namespace rtype::server {

ServerNetwork::ServerNetwork(network::INetwork &network)
	: network::Network(network)
{
	_handlers.emplace(std::make_pair(rtype::game::network::CONNECT, std::bind(&ServerNetwork::onConnect, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::DISCONNECT, std::bind(&ServerNetwork::onDisconnect, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::CREATE_SESSION, std::bind(&ServerNetwork::onCreateSession, this, std::placeholders::_1)));
}

void
ServerNetwork::start(std::size_t const &port)
{
	_network.createTCPEndpoint(port, std::bind(&ServerNetwork::onReceivePacket, this, std::placeholders::_1));
	std::cout << "server is listening on " << port << std::endl;
	_network.run();
}

void
ServerNetwork::onConnect(network::Packet &packet)
{
	std::cout << "connect" << std::endl;
}

void
ServerNetwork::onDisconnect(network::Packet &packet)
{
	std::cout << "disconnect" << std::endl;
}

void
ServerNetwork::onCreateSession(network::Packet &packet)
{
	std::cout << "here" << std::endl;
	std::cout << "creating session on port " << _network.getUnusedPort() << std::endl;
}

}
