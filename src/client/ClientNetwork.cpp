/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include <thread>

#include "ClientNetwork.hpp"
#include "GameNetwork.hpp"
#include "NetworkException.hpp"

namespace rtype::client {

ClientNetwork::ClientNetwork(network::INetwork &network)
	: network::Network(network)
	, _server_id(0)
	, _is_connected(false)
	, _has_joined_session(false)
{
	_handlers.emplace(std::make_pair(rtype::game::network::CONNECT, std::bind(&ClientNetwork::onConnect, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::DISCONNECT, std::bind(&ClientNetwork::onDisconnect, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::CREATE_SESSION, std::bind(&ClientNetwork::onCreateSession, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::JOIN_SESSION, std::bind(&ClientNetwork::onJoinSession, this, std::placeholders::_1)));
}

ClientNetwork::~ClientNetwork(void)
{
	_network.stop();
}

void
ClientNetwork::connect(std::string const &ip, std::size_t const &port, std::string const &username)
{
	network::Packet packet(game::network::CONNECT, username);

	_user = username;
	_server_ip = ip;
	_server_id = _network.connectToTCPServer(ip, port, std::bind(&ClientNetwork::onReceivePacket, this, std::placeholders::_1));
	_network.sendTCPData(packet, _server_id);
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
ClientNetwork::joinSession(std::string username)
{
	network::Packet packet(game::network::JOIN_SESSION, username);

	std::cout << "creating session" << std::endl;
	_network.sendTCPData(packet, _server_id);
}

void
ClientNetwork::connectToCurrentSession(void)
{
	auto packet = network::Packet(game::network::CONNECT, _user);

	while (true) {
		try {
			_session_id = _network.connectToTCPServer(_server_ip, _session_port, std::bind(&ClientNetwork::onReceivePacket, this, std::placeholders::_1));
			break;
		} catch (network::NetworkException) {
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
	_network.sendTCPData(packet, _session_id);
	_has_joined_session = true;
}


void
ClientNetwork::onConnect(network::Packet &packet)
{
	_is_connected = packet.getPayload<bool>();

	if (!_is_connected) {
		std::cerr << "fail to connect, try with another username" << std::endl;
	}
}

void
ClientNetwork::onDisconnect(network::Packet &packet)
{
	std::cout << "disconnect" << std::endl;
}

void
ClientNetwork::onCreateSession(network::Packet &packet)
{
	if (packet.getPayload<bool>()) {
		_session_port = packet.getPayload<std::size_t>();
		connectToCurrentSession();
	} else {
		std::cout << "fail to create session" << std::endl;
	}
}

void
ClientNetwork::onJoinSession(network::Packet &packet)
{
	if (packet.getPayload<bool>()) {
		_session_port = packet.getPayload<std::size_t>();
		connectToCurrentSession();
	} else {
		std::cout << "fail to connect to session" << std::endl;
	}
}

}
