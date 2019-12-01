/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef SERVERNETWORK_HPP_
#define SERVERNETWORK_HPP_

#include "Network.hpp"

namespace rtype::server {

	class ServerNetwork : public network::Network {
	// @MARK Constructors/Destructors
		public:
			ServerNetwork(network::INetwork &network);
			~ServerNetwork() = default;

	// @MARK Methods
		public:
			void start(std::size_t const &port);

	// @MARK Handlers
		private:
			void onConnect(network::Packet &packet);
			void onDisconnect(network::Packet &packet);
			void onCreateSession(network::Packet &packet);

	// @MARK Properties
		private:
	};

}

#endif /* !SERVERNETWORK_HPP_ */
