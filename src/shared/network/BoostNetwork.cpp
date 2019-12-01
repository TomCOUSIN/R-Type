/*
** EPITECH PROJECT, 2019
** boostNetwork
** File description:
** created by lucasmrdt
*/

#include <vector>
#include <cstddef>

#include "Shared.hpp"
#include "BoostNetwork.hpp"
#include "BoostNetworkException.hpp"

using namespace rtype::network;

NetworkSession::NetworkSession(tcp::socket socket, std::size_t socket_id, INetwork::PacketCallback callback):
    _socket(std::move(socket)),
    _socket_id(socket_id),
    _callback(callback)
{}

void
NetworkSession::doRead(void)
{
    auto packet = std::make_shared<Packet>();
    auto self(shared_from_this());

    packet->setSocketId(_socket_id);
    auto read_payload_cb = [this, self, packet](boost::system::error_code ec, std::size_t length) {
        if (ec) {
#ifdef DEBUG
            std::cout << "error: " << ec.message() << std::endl;
#endif
            return;
        }
        _callback(*packet);
        doRead();
    };
    auto read_header_cb = [this, self, packet, read_payload_cb](boost::system::error_code ec, std::size_t length) {
        if (ec || !length) {
#ifdef DEBUG
            std::cout << "error: " << ec.message() << std::endl;
#endif
            return;
        }
        packet->parseHeader();
        _socket.async_read_some(boost::asio::buffer(packet->payload(), packet->getPayloadSize()), read_payload_cb);
    };
    _socket.async_read_some(boost::asio::buffer(packet->header(), Packet::HEADER_SIZE), read_header_cb);
}

void
NetworkSession::doWrite(Packet &packet)
{
    auto self(shared_from_this());
    boost::system::error_code error;
    std::vector<char> buffer(Packet::HEADER_SIZE + packet.getPayloadSize());

    std::copy(static_cast<char*>(packet.header())
             , static_cast<char*>(packet.header()) + Packet::HEADER_SIZE
             , buffer.begin());
    std::copy(static_cast<char*>(packet.payload())
             , static_cast<char*>(packet.payload()) + packet.getPayloadSize()
             , buffer.begin() + Packet::HEADER_SIZE);
    _socket.async_write_some(boost::asio::buffer(buffer), [](boost::system::error_code ec, std::size_t length) {
#ifdef DEBUG
        std::cout << "error: " << ec.message() << std::endl;
        std::cout << "nb written: " << length << std::endl;
#endif
    });
}

BoostNetwork::BoostNetwork(void):
    _socket_id_counter(0),
    _io_service(),
    _io_context(),
    _emit_udp_socket(std::make_unique<udp::socket>(_io_service, udp::endpoint(udp::v4(), 0)))
{}

BoostNetwork::~BoostNetwork(void)
{
    for (auto &t : _threads) {
        std::cout << "thread " << t.joinable() << std::endl;
        if (t.joinable()) {
            t.join();
        }
    }
}

void
BoostNetwork::stop(void)
{
    _io_context.stop();
}

void
BoostNetwork::run(void)
{
    _io_context.run();
}

void
BoostNetwork::asyncRun(void)
{
    _threads.push_back(std::thread([this]() { _io_context.run(); }));
}


std::size_t
BoostNetwork::getUnusedPort(void)
{
    tcp::acceptor acceptor(_io_service, tcp::endpoint(tcp::v4(), 0));

    return acceptor.local_endpoint().port();
}

std::size_t
BoostNetwork::getUniqueSocketId(void) noexcept
{
    return ++_socket_id_counter;
}

void
BoostNetwork::createUDPEndpoint(std::size_t const &port, PacketCallback const callback)
{
    auto udp_socket = std::make_shared<udp::socket>(_io_service);
    auto socket_id = getUniqueSocketId();

    udp_socket->open(udp::v4());
    udp_socket->bind(udp::endpoint(address_v4::any(), port));
    std::thread(&BoostNetwork::readUDPData, this, udp_socket, callback).detach();
}

void
BoostNetwork::sendUDPData(Packet &packet, std::string const &ip, std::size_t const &port)
{
    udp::resolver resolver(_io_service);
    udp::resolver::query query(udp::v4(), ip, std::to_string(port));
    auto endpoint = *resolver.resolve(query);

    _emit_udp_socket->send_to(boost::asio::buffer(packet.header(), Packet::HEADER_SIZE), endpoint);
    _emit_udp_socket->send_to(boost::asio::buffer(packet.payload(), packet.getPayloadSize()), endpoint);
}

void
BoostNetwork::readUDPData(std::shared_ptr<udp::socket> socket, PacketCallback const callback)
{
    network::Packet packet;
    udp::endpoint remote_endpoint;
    boost::system::error_code error;

    while (true) {
        socket->receive_from(boost::asio::buffer(packet.header(), Packet::HEADER_SIZE), remote_endpoint, 0, error);
        if (error) {
            throw BoostNetworkException("An error occurred during reading from the socket (UDP).");
        }
        packet.parseHeader();
        if (!packet.isValid()) {
            continue;
        }
        socket->receive_from(boost::asio::buffer(packet.payload(), packet.getPayloadSize()), remote_endpoint, 0, error);
        if (error) {
            throw BoostNetworkException("An error occurred during reading from the socket (UDP).");
        }
        packet.setIp(remote_endpoint.address().to_string());
        packet.setPort(remote_endpoint.port());
        callback(packet);
    }
}

void
BoostNetwork::createTCPEndpoint(std::size_t const &port, PacketCallback const callback)
{
    _acceptor = std::make_unique<tcp::acceptor>(_io_context, tcp::endpoint(tcp::v4(), port));

    tcpDoAccept(callback);
}

std::size_t
BoostNetwork::connectToTCPServer(std::string const &ip, std::size_t const &port, PacketCallback const callback)
{
    auto tcp_socket = tcp::socket(_io_context);
    auto socket_id = getUniqueSocketId();

    tcp_socket.connect(tcp::endpoint(address::from_string(ip), port));
    if (!tcp_socket.is_open()) {
        throw BoostNetworkException("Connection not established.");
    }
    auto session = std::make_shared<NetworkSession>(std::move(tcp_socket), socket_id, callback);
    _tcp_sessions_by_id[socket_id] = session;
    session->doRead();
    return socket_id;
}

void
BoostNetwork::sendTCPData(Packet &packet, std::size_t const &socket_id)
{
    std::shared_ptr<NetworkSession> tcp_session;

    try {
        tcp_session = _tcp_sessions_by_id[socket_id];
    }
    catch (std::out_of_range) {
        throw BoostNetworkException(std::string("Unfound socket id : '") + std::to_string(socket_id) + std::string("'."));
    }

    tcp_session->doWrite(packet);
}

void
BoostNetwork::tcpDoAccept(PacketCallback const callback)
{
    std::cout << "a" << std::endl;
    _acceptor->async_accept(
        [this, callback](boost::system::error_code ec, tcp::socket socket)
        {
            std::cout << "b" << std::endl;
            if (ec) {
                std::cout << ec.message() << std::endl;
                return;
            }
            auto socket_id = getUniqueSocketId();
            auto tcp_session = std::make_shared<NetworkSession>(std::move(socket), socket_id, callback);
            _tcp_sessions_by_id[socket_id] = tcp_session;
            tcp_session->doRead();
            tcpDoAccept(callback);
        }
    );
}
