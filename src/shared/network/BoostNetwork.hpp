/*
** EPITECH PROJECT, 2019
** boostNetwork
** File description:
** network implementation with qt
*/

#ifndef BOOST_NETWORK_HPP_
#define BOOST_NETWORK_HPP_

#include <map>
#include <memory>
#include <boost/asio.hpp>

#include "INetwork.hpp"
#include "Packet.hpp"

namespace rtype::network {

    using boost::asio::ip::tcp;
    using boost::asio::ip::udp;
    using boost::asio::ip::address;
    using boost::asio::ip::address_v4;

    class NetworkSession : public std::enable_shared_from_this<NetworkSession> {
    // @MARK Constructors/Destructors
        public:
        NetworkSession(tcp::socket socket, std::size_t socket_id, INetwork::PacketCallback callback);

    // @MARK Methods
        public:
        void doRead(void);
        void doWrite(Packet &packet);

    // @MARK Properties
        private:
        tcp::socket _socket;
        std::size_t _socket_id;
        INetwork::PacketCallback _callback;
    };

    class BoostNetwork: public INetwork {
    // @MARK Constructors/Destructors
        public:
        BoostNetwork(void);
        virtual ~BoostNetwork(void);

    // @MARK Methods
        public:
        virtual void stop(void);
        virtual void run(void);
        virtual void asyncRun(void);
        virtual std::size_t getUnusedPort(void);

        private:
        std::size_t getUniqueSocketId(void) noexcept;

    // @MARK Methods - UDP
        public:
        virtual void createUDPEndpoint(std::size_t const &port, PacketCallback const callback);
        virtual void sendUDPData(Packet &packet, std::string const &ip, std::size_t const &port);

    // @MARK Methods - TCP
        public:
        virtual std::size_t connectToTCPServer(std::string const &ip, std::size_t const &port, PacketCallback const callback);
        virtual void createTCPEndpoint(std::size_t const &port, PacketCallback const callback);
        virtual void sendTCPData(Packet &packet, std::size_t const &socket_id);

    // @MARK Methods - Boost Asio
        private:
        void readUDPData(std::shared_ptr<udp::socket> socket, PacketCallback const callback);
        void tcpDoAccept(PacketCallback const callback);
        void readTCPData(tcp::socket socket, PacketCallback const callback);

    // @MARK Properties
        private:
        std::size_t	_socket_id_counter;
        boost::asio::io_service _io_service;
        boost::asio::io_context _io_context;
        std::vector<std::thread> _threads;

        std::unique_ptr<tcp::acceptor> _acceptor;

        std::unique_ptr<udp::socket> _emit_udp_socket;
        std::unique_ptr<tcp::endpoint> _tcp_server;
        std::map<std::size_t, std::shared_ptr<NetworkSession>> _tcp_sessions_by_id;
        std::map<std::size_t, std::shared_ptr<udp::socket>> _udp_sockets_by_id;

    };

}

#endif /* !BOOST_NETWORK_HPP_ */
