/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef SERVER_SESSION_HPP_
#define SERVER_SESSION_HPP_

#include "Network.hpp"

namespace rtype::server {

	class ServerSession : public network::Network {
	// @MARK Constructors/Destructors
		public:
		/**
		 * @brief Construct a new Server Session object
		 *
		 * @param network network implementation
		 */
		ServerSession(network::INetwork &network);

		/**
		 * @brief Destroy the Server Session object
		 */
		~ServerSession() = default;

	// @MARK Methods
		public:
		/**
		 * @brief Start session on specified port
		 *
		 * @param port Listening port
		 */
		void start(std::size_t const &port);

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

	// @MARK Properties
		private:
	};

}

#endif /* !SERVER_SESSION_HPP_ */
