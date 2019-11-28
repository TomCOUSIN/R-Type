/*
** EPITECH PROJECT, 2019
** boostNetwork
** File description:
** network implementation with qt
*/

#include <vector>
#include <cstddef>

#include "BoostNetwork.hpp"
#include "BoostNetworkException.hpp"

using namespace rtype::network;

BoostNetwork::BoostNetwork(void):
    _socket_id_counter(0),
    _io_service(),
    _emit_udp_socket(std::make_unique<udp::socket>(_io_service, udp::endpoint(udp::v4(), 0)))
{}

BoostNetwork::~BoostNetwork(void)
{
    for (auto &t : _threads) {
        if (t.joinable()) {
            t.join();
        }
    }
}

std::size_t
BoostNetwork::getUniqueSocketId(void) noexcept
{
    return ++_socket_id_counter;
}

void
BoostNetwork::createUDPEndpoint(std::size_t const &port, packet_callback_t const callback)
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
BoostNetwork::createTCPEndpoint(std::size_t const &port, packet_callback_t const callback)
{
    tcp::acceptor acceptor(_io_service, tcp::endpoint(tcp::v4(), port));

    while (true) {
        std::thread(&BoostNetwork::readTCPData, this, acceptor.accept(), callback).detach();
    }
}

std::size_t
BoostNetwork::connectToTCPServer(std::string const &ip, std::size_t const &port, packet_callback_t const callback)
{
    auto tcp_socket = std::make_shared<tcp::socket>(_io_service);
    auto socket_id = getUniqueSocketId();

    tcp_socket->connect(tcp::endpoint(address::from_string(ip), port));
    if (!tcp_socket->is_open()) {
        throw BoostNetworkException("Connection not established.");
    }
    _tcp_sockets_by_id[socket_id] = tcp_socket;
    _listeners_by_id[socket_id] = callback;
    return socket_id;
}

void
BoostNetwork::sendTCPData(Packet &packet, std::size_t const &socket_id)
{
    std::vector<char>	buffer(Packet::HEADER_SIZE + packet.getPayloadSize());
    std::shared_ptr<tcp::socket> tcp_socket;
    boost::system::error_code error;

    try {
        tcp_socket = _tcp_sockets_by_id[socket_id];
    }
    catch (std::out_of_range) {
        throw BoostNetworkException(std::string("Unfound socket id : '") + std::to_string(socket_id) + std::string("'."));
    }
    std::copy(static_cast<char*>(packet.header()), static_cast<char*>(packet.header()) + Packet::HEADER_SIZE, buffer.begin());
    std::copy(static_cast<char*>(packet.payload()), static_cast<char*>(packet.payload()) + packet.getPayloadSize(), buffer.begin() + Packet::HEADER_SIZE);
    boost::asio::write(*tcp_socket, boost::asio::buffer(buffer), error);
    if (error) {
        throw BoostNetworkException("An error occurred during writing to the socket (TCP).");
    }
}

void
BoostNetwork::readUDPData(std::shared_ptr<udp::socket> socket, packet_callback_t const callback)
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
BoostNetwork::readTCPData(tcp::socket socket, packet_callback_t const callback)
{
    auto endpoint = socket.remote_endpoint();
    auto socket_id = getUniqueSocketId();
    Packet packet;

    packet.setIp(endpoint.address().to_string());
    packet.setPort(endpoint.port());
    _tcp_sockets_by_id[socket_id] = std::shared_ptr<tcp::socket>(&socket);
    packet.setSocketId(socket_id);
    try {
        while (true) {
            boost::asio::read(socket, boost::asio::buffer(packet.header(), Packet::HEADER_SIZE));
            packet.parseHeader();
            if (!packet.isValid()) {
                continue;
            }
            boost::asio::read(socket, boost::asio::buffer(packet.payload(), packet. getPayloadSize()));
            callback(packet);
        }
    } catch (std::exception) {
        packet.setSocketId(socket_id);
        // packet.setType(Packet::Type::DISCONNECT);
        // callback(packet);
    }
}
