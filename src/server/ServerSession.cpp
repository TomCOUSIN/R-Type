/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include <functional>
#include <thread>

#include "ServerSession.hpp"
#include "GameNetwork.hpp"

namespace rtype::server {

ServerSession::ServerSession(network::INetwork &network)
	: network::Network(network)
{
	_handlers.emplace(std::make_pair(rtype::game::network::CONNECT, std::bind(&ServerSession::onConnect, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::DISCONNECT, std::bind(&ServerSession::onDisconnect, this, std::placeholders::_1)));
}

void
ServerSession::start(std::size_t const &port)
{
	_network.createTCPEndpoint(port, std::bind(&ServerSession::onReceivePacket, this, std::placeholders::_1));
	_network.createUDPEndpoint(port, std::bind(&ServerSession::onReceivePacket, this, std::placeholders::_1));
	std::cout << "session is listening on " << port << std::endl;
	_network.run();
}

void
ServerSession::onConnect(network::Packet &packet)
{
	std::cout << "connect" << std::endl;
}

void
ServerSession::onDisconnect(network::Packet &packet)
{
	std::cout << "disconnect" << std::endl;
}

}
