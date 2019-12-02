/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include <functional>
#include <thread>

#include "GameSession.hpp"
#include "Game.hpp"
#include "CollableEntity.hpp"
#include "CollisionSystem.hpp"
#include "Speed.hpp"
#include "Position.hpp"

namespace rtype::server {

GameSession::GameSession(network::INetwork &network, engine::GameEngine &engine)
	: network::Network(network)
	, _engine(engine)
{
	_handlers.emplace(std::make_pair(rtype::game::network::CONNECT, std::bind(&GameSession::onConnect, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::DISCONNECT, std::bind(&GameSession::onDisconnect, this, std::placeholders::_1)));
	_handlers.emplace(std::make_pair(rtype::game::network::INPUT, std::bind(&GameSession::onInput, this, std::placeholders::_1)));
}

void
GameSession::start(std::size_t const &session_port)
{
    _engine.loadSystem<engine::system::CollisionSystem>(_engine);
    _engine.loadComponentStorage<engine::component::Position>();
    _engine.loadComponentStorage<engine::component::Speed>();

	_network.createTCPEndpoint(session_port, std::bind(&GameSession::onReceivePacket, this, std::placeholders::_1));
	_network.createUDPEndpoint(session_port, std::bind(&GameSession::onReceivePacket, this, std::placeholders::_1));
	std::cout << "session is listening on " << session_port << std::endl;
	_network.run();
}

void
GameSession::onConnect(network::Packet &packet)
{
	auto user_port = _network.getUnusedPort();
	auto user = packet.getPayload<std::string>();
	auto player = engine::entity::CollableEntity(_engine, 300, 300, 33, 17, 3, 3);

	auto connection_packet = network::Packet(game::network::CONNECT, user_port);
	_network.sendTCPData(connection_packet, packet.getSocketId());

	auto response_packet = network::Packet(game::network::CREATE_PLAYER);
	response_packet << *player.getPosition();
	response_packet << user;
	for (auto &id : _connections) {
		_network.sendTCPData(response_packet, id.second);
	}

	_connections.emplace(user, packet.getSocketId());
	_udp_connections.emplace(user, std::make_pair(packet.getIp(), user_port));
	_players.emplace(user, player);

	for (auto &player : _players) {
		auto p = network::Packet(game::network::CREATE_PLAYER);
		p << *player.second.getPosition();
		p << std::string(player.first);
		std::cout << "send " << player.first << " to " << user << std::endl;
		_network.sendTCPData(p, packet.getSocketId());
	}

	std::cout << "connect success of " << user << std::endl;
}

void
GameSession::onDisconnect(network::Packet &packet)
{
	std::cout << "disconnect" << std::endl;
}

void
GameSession::onInput(network::Packet &packet)
{
	auto input = packet.getPayload<engine::event::EventType>();
	auto user = packet.getPayload<std::string>();
	auto entity = _players.find(user);
	std::cout << "input" << std::endl;

	if (entity == _players.end()) {
		std::cout << "unfound user " << user << " in current players" << std::endl;
		return;
	}

	std::cout << "input-b" << std::endl;
	auto position = entity->second.getPosition();
	switch (input) {
	case game::event::ARROW_DOWN:
		position->y += 10;
		break;
	case game::event::ARROW_UP:
		position->y -= 10;
		break;
	case game::event::ARROW_RIGHT:
		position->x += 10;
		break;
	case game::event::ARROW_LEFT:
		position->x -= 10;
		break;
	default:
		std::cerr << "unfound input " << input << std::endl;
		break;
	}

	auto response_packet = network::Packet(game::network::MOVE_PLAYER);
	response_packet << *position;
	response_packet << user;
	for (auto &id : _udp_connections) {
		std::cout << "send to " << id.first << std::endl;
		_network.sendUDPData(response_packet, id.second.first, id.second.second);
	}
}

}
