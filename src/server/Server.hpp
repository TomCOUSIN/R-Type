/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <unordered_map>

#include "Network.hpp"
#include "GameEngine.hpp"

namespace rtype::server {

	class Server : public network::Network {
	// @MARK Constructors/Destructors
		public:
		/**
		 * @brief Construct a new Server Network object
		 *
		 * @param network network implementation
		 */
		Server(network::INetwork &network, engine::GameEngine &engine);

		/**
		 * @brief Destroy the Server Network object
		 */
		~Server() = default;

	// @MARK Methods
		public:
		/**
		 * @brief Start the server on specified port
		 *
		 * @param port Listening port
		 */
		void start(std::size_t const &port);

		private:
		/**
		 * @brief Create a Session (party)
		 *
		 * @param session_port Listening port of the session
		 */
		void createSession(std::size_t const &session_port);

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

		/**
		 * @brief On Create session handler
		 *
		 * @param packet network packet
		 */
		void onCreateSession(network::Packet &packet);

		/**
		 * @brief On Join session handler
		 *
		 * @param packet network packet
		 */
		void onJoinSession(network::Packet &packet);

	// @MARK Properties
		private:
		engine::GameEngine &_engine;

		/**
		 * @brief Session port by users
		 */
		std::unordered_map<std::string, std::size_t> _session_port_by_users;

		/**
		 * @brief Socket id by usernames
		 */
		std::unordered_map<std::string, std::size_t> _socket_id_by_users;

		/**
		 * @brief Username by socket ids
		 */
		std::unordered_map<std::size_t, std::string> _user_by_socket_ids;
	};

}

#endif /* !SERVER_HPP_ */
