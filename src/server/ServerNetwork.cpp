/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include <functional>
#include <thread>

#include "ServerNetwork.hpp"
#include "GameNetwork.hpp"
#include "ServerSession.hpp"
#include "Fork.hpp"

namespace rtype::server {

ServerNetwork::ServerNetwork(network::INetwork &network)
	: network::Network(network)
{
	_handlers.emplace(std::make_pair(rtype::game::network::CONNECT, std::bind(&ServerNetwork::onConnect, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::DISCONNECT, std::bind(&ServerNetwork::onDisconnect, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::CREATE_SESSION, std::bind(&ServerNetwork::onCreateSession, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::JOIN_SESSION, std::bind(&ServerNetwork::onJoinSession, this, std::placeholders::_1)));
}

void
ServerNetwork::start(std::size_t const &port)
{
	_network.createTCPEndpoint(port, std::bind(&ServerNetwork::onReceivePacket, this, std::placeholders::_1));
	std::cout << "server is listening on " << port << std::endl;
	_network.run();
}

void
ServerNetwork::createSession(std::size_t const &session_port)
{
	auto new_network = _network.duplicate();
	ServerSession(*new_network).start(session_port);
}

void
ServerNetwork::onConnect(network::Packet &packet)
{
	auto user = packet.getPayload<std::string>();
	auto response_packet = network::Packet(game::network::CONNECT);
	auto founded_user = _socket_id_by_users.find(user);

	if (founded_user == _socket_id_by_users.end()) {
		response_packet << true;
		_user_by_socket_ids.emplace(std::make_pair(packet.getSocketId(), user));
		_socket_id_by_users.emplace(std::make_pair(user, packet.getSocketId()));
		std::cout << user << " is now connect" << std::endl;
	} else {
		response_packet << false;
	}
	_network.sendTCPData(response_packet, packet.getSocketId());
}

void
ServerNetwork::onDisconnect(network::Packet &packet)
{
	std::cout << "disconnect" << std::endl;
}

void
ServerNetwork::onCreateSession(network::Packet &packet)
{
	std::size_t session_port = _network.getUnusedPort();
	auto child_starter = std::bind(&ServerNetwork::createSession, this, session_port);
	auto user = _user_by_socket_ids.find(packet.getSocketId());
	auto response_packet = network::Packet(game::network::CREATE_SESSION);

	if (user != _user_by_socket_ids.end()) {
		rtype::encapsulation::Fork::start(child_starter);
		_session_port_by_users.emplace(std::make_pair(user->second, session_port));
		response_packet << true;
		response_packet << session_port;
	} else {
		response_packet << false;
	}
	_network.sendTCPData(response_packet, packet.getSocketId());
}

void
ServerNetwork::onJoinSession(network::Packet &packet)
{
	auto user_session = packet.getPayload<std::string>();
	network::Packet response_packet(game::network::JOIN_SESSION);

	auto session = _session_port_by_users.find(user_session);
	if (session != _session_port_by_users.end()) {
		response_packet << true;
		response_packet << session->second;
	} else {
		response_packet << false;
	}
	_network.sendTCPData(response_packet, packet.getSocketId());
}

}
