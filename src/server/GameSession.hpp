/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef SERVER_SESSION_HPP_
#define SERVER_SESSION_HPP_

#include <unordered_map>

#include "Network.hpp"
#include "GameEngine.hpp"
#include "CollableEntity.hpp"

namespace rtype::server {

	class GameSession : public network::Network {
	// @MARK Constructors/Destructors
		public:
		/**
		 * @brief Construct a new Server Session object
		 *
		 * @param network network implementation
		 */
		GameSession(network::INetwork &network, engine::GameEngine &engine);

		/**
		 * @brief Destroy the Server Session object
		 */
		~GameSession() = default;

	// @MARK Methods
		public:
		/**
		 * @brief Start session on specified port
		 *
		 * @param port Listening port
		 */
		void start(std::size_t const &session_port);

	// @MARK Handlers
		private:
		/**
		 * @brief On Connect handler
		 *
		 * @param packet network packet
		 */
		void onConnect(network::Packet &packet);

		/**
		 * @brief On Disconnect handler
		 *
		 * @param packet network packet
		 */
		void onDisconnect(network::Packet &packet);

		void onInput(network::Packet &packet);

		void onMouse(network::Packet &packet);

		void onFire(network::Packet &packet);

		void onStartGame(network::Packet &packet);

	// @MARK Properties
		private:
		engine::GameEngine &_engine;
        std::unordered_map<std::string, std::pair<std::string, std::size_t>> _udp_connections;
        std::unordered_map<std::string, std::size_t> _tcp_connections;
        std::unordered_map<std::string, engine::entity::CollableEntity> _players;
	};

}

#endif /* !SERVER_SESSION_HPP_ */
