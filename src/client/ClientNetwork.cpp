/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include "ClientNetwork.hpp"
#include "GameNetwork.hpp"

namespace rtype::client {

ClientNetwork::ClientNetwork(network::INetwork &network)
	: network::Network(network)
	, _server_id(0)
{
	_handlers.emplace(std::make_pair(rtype::game::network::CONNECT, std::bind(&ClientNetwork::onConnect, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::DISCONNECT, std::bind(&ClientNetwork::onDisconnect, this, std::placeholders::_1)));
}

void
ClientNetwork::connect(std::string const &ip, std::size_t const &port, std::string const &username)
{
	network::Packet packet(game::network::CONNECT, username);

	_server_id = _network.connectToTCPServer(ip, port, std::bind(&ClientNetwork::onReceivePacket, this, std::placeholders::_1));
	_network.sendTCPData(packet, _server_id);
	std::cout << "client is connected to " << ip << ":" << port << std::endl;
	_network.asyncRun();
}

void
ClientNetwork::createSession(void)
{
	network::Packet packet(game::network::CREATE_SESSION);

	std::cout << "creating session" << std::endl;
	_network.sendTCPData(packet, _server_id);
}

void
ClientNetwork::onConnect(network::Packet &packet)
{
	std::cout << "connect" << std::endl;
}

void
ClientNetwork::onDisconnect(network::Packet &packet)
{
	std::cout << "disconnect" << std::endl;
}

}
