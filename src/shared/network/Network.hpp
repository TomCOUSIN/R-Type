/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef CPP_RTYPE_2019_NETWORK_HPP
#define CPP_RTYPE_2019_NETWORK_HPP

#include <unordered_map>
#include <functional>

#include "Packet.hpp"
#include "INetwork.hpp"

namespace rtype::network {

	class Network {

	// @MARK Types
		public:
		using PacketHandler = std::unordered_map<Packet::PacketType, INetwork::PacketCallback>;

	// @MARK Constants
		public:
		#define LOCALHOST ("127.0.0.1")

	// @MARK Constructors/Destructors
		public:
		Network(INetwork &network);
		~Network(void);

	// @MARK Opperators
		public:
		Network(const Network &) = delete;
		Network(Network &&) = delete;
		Network &operator=(const Network &) = delete;
		Network &operator=(Network &&) = delete;

	// @MARK Methods
		public:
		void subscribeTo(Packet::PacketType type, INetwork::PacketCallback callback);
		protected:
		void onReceivePacket(Packet &packer);

	// @MARK Attributes
		protected:
		INetwork &_network;
		PacketHandler _handlers;

	};

}

#endif /* !CPP_RTYPE_2019_NETWORK_HPP */
