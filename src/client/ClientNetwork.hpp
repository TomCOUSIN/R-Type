/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef CLIENTNETWORK_HPP_
#define CLIENTNETWORK_HPP_

#include "Network.hpp"
#include "Event.hpp"
#include "Position.hpp"

namespace rtype::client {

	class ClientNetwork : public network::Network {
	// @MARK Constructors/Destructors
		public:
		/**
		 * @brief Construct a new Client Network object
		 *
		 * @param network Network implementation
		 */
		ClientNetwork(network::INetwork &network);

		/**
		 * @brief Destroy the Client Network object
		 */
		~ClientNetwork();

	// @MARK Methods
		public:
		/**
		 * @brief Connect to remote server
		 *
		 * @param ip remote ip
		 * @param port remote port
		 * @param username user username
		 */
		void connect(std::string const &ip, std::size_t const &port, std::string const &username);

		/**
		 * @brief Create a Session (party)
		 */
		void createSession(void);

		/**
		 * @brief Join a session (party)
		 *
		 * @param username username of the session's hoster
		 */
		void joinSession(std::string username);

		void sendInput(engine::event::EventType input);

		void sendMouse(engine::component::Position position);

		void startGame(void);

		private:
		/**
		 * @brief Connect to the remote session
		 */
		void connectToCurrentSession(void);

	// @MARK Getters
		public:
		/**
		 * @brief User is connected
		 */
		bool isConnected(void) const noexcept { return _is_connected; };

		/**
		 * @brief User has joined a session (party)
		 */
		bool hasJoinedSession(void) const noexcept { return _has_joined_session; };

	// @MARK Handlers
		private:
		/**
		 * @brief On connect handler
		 *
		 * @param packet Network packet
		 */
		void onConnect(network::Packet &packet);
		void onConnectSession(network::Packet &packet);

		/**
		 * @brief On disconnect handler
		 *
		 * @param packet Network packet
		 */
		void onDisconnect(network::Packet &packet);

		/**
		 * @brief On create session handler
		 *
		 * @param packet Network packet
		 */
		void onCreateSession(network::Packet &packet);

		/**
		 * @brief On join session handler
		 *
		 * @param packet Network packet
		 */
		void onJoinSession(network::Packet &packet);

	// @MARK Properties
		private:
		/**
		 * @brief is user connected
		 */
		bool _is_connected;

		/**
		 * @brief has joined session
		 */
		bool _has_joined_session;

		/**
		 * @brief the current user
		 */
		std::string _user;

		/**
		 * @brief remote server socket id
		 */
		std::size_t _server_id;

		/**
		 * @brief remote server ip
		 */
		std::string _server_ip;

		/**
		 * @brief remote session port
		 */
		std::size_t _local_port;
		std::size_t _session_port;

		/**
		 * @brief remote session socket id
		 */
		std::size_t _session_id;
	};

}

#endif /* !CLIENTNETWORK_HPP_ */
