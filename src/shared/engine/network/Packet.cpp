/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Packet.cpp
*/

#include "Packet.hpp"

namespace rtype::network {

    void
    Packet::parseHeader(void) noexcept
    {
        _payload.resize(_header.payload_size);
    }

    const std::size_t
    Packet::getSize(void) const noexcept
    {
        return Packet::HEADER_SIZE + _payload.size();
    }

    const std::size_t
    Packet::getPayloadSize(void) const noexcept
    {
        return _header.payload_size;
    }

    const std::size_t
    Packet::getSocketId(void) const noexcept
    {
        return _socket_id;
    }

    const std::string
    Packet::getIp(void) const noexcept
    {
        return _ip;
    }

    const std::size_t
    Packet::getPort(void) const noexcept
    {
        return _port;
    }

    void
    Packet::setIp(const std::string &ip) noexcept
    {
        _ip = ip;
    }

    void
    Packet::setPort(std::size_t port) noexcept
    {
        _port = port;
    }

    void
    Packet::setSocketId(const std::size_t &socket_id) noexcept
    {
        _socket_id = socket_id;
    }

    void *
    Packet::payload(void) noexcept
    {
        return _payload.data();
    }

    void *
    Packet::header(void) noexcept
    {
        return &_header;
    }

    void
    Packet::clearPayload(void) noexcept
    {
        _payload.clear();
    }

    bool
    Packet::isValid(void) noexcept
    {
        return _header.magic_number == MAGIC_NUMBER;
    }

}
