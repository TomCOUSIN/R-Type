/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef CPP_RTYPE_2019_NETWORK_HPP
#define CPP_RTYPE_2019_NETWORK_HPP

#include "Packet.hpp"
#include "INetwork.hpp"

namespace rtype::network {

	class GameNetwork {

	// @MARK Types
		public:
		enum MessageType {
			LOAD_MAP = 1 << 0,
			USER_EVENT = 1 << 1,
			POSITIONS = 1 << 2,
			CONNECTION = 1 << 3,
			DISCONNECTION = 1 << 4,
		};

	// @MARK Constants
		public:
		#define CALL_ENDPOINT_PORT (8081)
		#define CALL_LISTENER_PORT (8080)
		#define LOCALHOST ("127.0.0.1")

	// @MARK Constructors/Destructors
		public:
		GameNetwork(INetwork &network, INetwork::packet_handlers_t handlers);
		~GameNetwork(void) = default;

	// @MARK Opperators
		public:
		GameNetwork(const GameNetwork &) = delete;
		GameNetwork(GameNetwork &&) = delete;
		GameNetwork &operator=(const GameNetwork &) = delete;
		GameNetwork &operator=(GameNetwork &&) = delete;

	// @MARK Methods
		protected:
		void onReceivePacket(Packet &packer);

	// @MARK Attributes
		protected:
		INetwork &_network;
		INetwork::packet_handlers_t _handlers;

	};

}

#endif /* !CPP_RTYPE_2019_NETWORK_HPP */
