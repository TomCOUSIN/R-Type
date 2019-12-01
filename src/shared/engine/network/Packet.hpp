/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Created by lucasmrdt
*/

#ifndef CPP_BABEL_2019_PACKET_HPP
#define CPP_BABEL_2019_PACKET_HPP

#include <cstddef>
#include <string>
#include <vector>

#include "PacketException.hpp"

namespace rtype::network {

    class Packet {

    // @MARK Types
        public:
        struct Header {
            std::uint16_t magic_number = MAGIC_NUMBER;
            std::uint16_t payload_size = 0;
        };

    // @MARK Constructors/Destructors
        public:
        /**
         * @brief Construct a new Packet object
         */
        Packet(void) = default;

        Packet(Packet &) = default;

        /**
         * @brief Construct a new Packet object with type and payload
         *
         * @tparam T payload's type
         * @param type packet's type
         * @param payload packet's payload
         */
        template <typename T>
        Packet(T const &payload)
            : Packet()
        {
            *this << payload;
        }

        ~Packet(void) = default;

    // @MARK Setters/Getters
        public:
        /**
         * @brief Get the packet's size
         *
         * @return packet's size
         */
        const std::size_t getSize(void) const noexcept;

        /**
         * @brief Get the packet's socket ID
         *
         * @return packet's socket id
         */
        const std::size_t getSocketId(void) const noexcept;

        /**
         * @brief Get the packet's payload size
         *
         * @return packet's payload size
         */
        const std::size_t getPayloadSize(void) const noexcept;

        /**
         * @brief Get the packet's remote IP
         *
         * @return packet's ip
         */
        const std::string getIp(void) const noexcept;

        /**
         * @brief Get the packet's remote port
         *
         * @return packet's port
         */
        const std::size_t getPort(void) const noexcept;

        /**
         * @brief Set the packet's ip
         *
         * @param string packet's ip
         */
        void setIp(const std::string &ip) noexcept;

        /**
         * @brief Set the packet's port
         *
         * @param size_t packet's port
         */
        void setPort(std::size_t port) noexcept;

        /**
         * @brief Set the packet's socket id
         *
         * @param string packet's socket id
         */
        void setSocketId(const std::size_t &socket_id) noexcept;

    // @MARK Methods
        public:
        /**
         * @brief parse the header, this is necessary to if you want to copy something into payload
         */
        void parseHeader(void) noexcept;

        /**
         * @brief get the payload's data pointer
         *
         * @return the payload's data pointer
         */
        void *payload(void) noexcept;

        /**
         * @brief get the payload's header pointer
         *
         * @return the payload's header pointer
         */
        void *header(void) noexcept;

        /**
         * @brief clear payload
         */
        void clearPayload(void) noexcept;

        /**
         * @brief test if the packet is valid
         */
        bool isValid(void) noexcept;

    // @MARK Operators
        /**
         * @brief Add a list of elements as payload
         *
         * @tparam Container List type
         * @tparam T Element of list type
         * @param list The list which is added to the packet's payload
         * @return Packet
         */
        template <template <typename... Args> class Container, typename T>
        Packet &
        operator<<(Container<T> const &list) noexcept
        {
            for (const T &element : list) {
                *this << element;
            }
            return *this;
        }

        /**
         * @brief Extract payload as list of items
         *
         * @tparam Container List type
         * @tparam T Element of list type
         * @param list The list in which the payload will be added
         * @return Packet
         */
        template <template <typename... Args> class Container, typename T>
        Packet &
        operator>>(Container<T> &list) noexcept
        {
            T new_element;

            while (_payload.size() > 0) {
                *this >> new_element;
                list.push_back(new_element);
            }
            return *this;
        }

        /**
         * @brief Add element to payload
         *
         * @tparam T Element type
         * @param element The element which is added to payload
         * @return Packet
         */
        template <typename T>
        Packet &
        operator<<(T const &element) noexcept
        {
            const auto raw_bytes = reinterpret_cast<const std::byte*>(&element);

            _payload.insert(_payload.end(), raw_bytes, raw_bytes + sizeof(T));
            _header.payload_size += sizeof(T);
            return *this;
        }

        /**
         * @brief Extract payload to element
         *
         * @tparam T Element type
         * @param element The element in which the payload is exported
         * @return Packet
         */
        template <typename T>
        Packet &
        operator>>(T &element)
        {
            const auto data = _payload.data();

            if (_payload.size() < sizeof(T)) {
                throw PacketException("not enough payload to be extracted from packet");
            }
            element = *reinterpret_cast<T*>(data);
            _payload.erase(_payload.begin(), _payload.begin() + sizeof(T));
            _header.payload_size -= sizeof(T);
            return *this;
        }

    // @MARK Properties
        public:
        static const std::size_t HEADER_SIZE = sizeof(Header);
        static const std::uint16_t MAGIC_NUMBER = 4242;

        private:
        Header _header;
        std::size_t _socket_id;
        std::string _ip;
        std::size_t _port;
        std::vector<std::byte> _payload;

    };

}

#endif /* !CPP_BABEL_2019_PACKET_HPP */
