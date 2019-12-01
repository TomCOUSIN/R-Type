/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef CLIENTNETWORK_HPP_
#define CLIENTNETWORK_HPP_

#include "Network.hpp"

namespace rtype::client {

	class ClientNetwork : public network::Network {
	// @MARK Constructors/Destructors
		public:
			ClientNetwork(network::INetwork &network);
			~ClientNetwork() = default;

	// @MARK Methods
		public:
			void connect(std::string const &ip, std::size_t const &port, std::string const &username);
			void createSession(void);

	// @MARK Handlers
		private:
			void onConnect(network::Packet &packet);
			void onDisconnect(network::Packet &packet);

	// @MARK Properties
		private:
			std::size_t _server_id;
	};

}

#endif /* !CLIENTNETWORK_HPP_ */
