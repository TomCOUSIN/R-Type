/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef CPP_RTYPE_2019_I_NETWORK_HPP
#define CPP_RTYPE_2019_I_NETWORK_HPP

#include <functional>
#include <string>
#include <map>

#include "Packet.hpp"

namespace rtype::network {

    class INetwork {

    // @MARK Types
        public:
        using packet_callback_t = std::function<void(Packet &)>;

    // @MARK Constructors/Destrcutors
        public:
        virtual ~INetwork(void) = default;

    // @MARK Methods - UDP Network
        public:
        /**
         * @brief create UDP endpoint
         *
         * @param port listening port
         * @param callback callback function fired when data is received
         */
        virtual void createUDPEndpoint(std::size_t const &port, packet_callback_t const callback) = 0;

        /**
         * @brief send packet via UDP
         *
         * @param packet packet containing data
         * @param ip target ip
         * @param port target port
         */
        virtual void sendUDPData(Packet &packet, std::string const &ip, std::size_t const &port) = 0;

    // @MARK Methods - TCP Network
        public:
        /**
         * @brief create TCP endpoint
         *
         * @param port listening port
         * @param callback callback function fired when data is received
         */
        virtual void createTCPEndpoint(std::size_t const &port, packet_callback_t const callback) = 0;

        /**
         * @brief connect to tcp server
         *
         * @param ip remote server ip
         * @param port remote server port
         * @param callback callback function fired when data is received
         * @return socket id
         */
        virtual std::size_t connectToTCPServer(std::string const &ip, std::size_t const &port, packet_callback_t const callback) = 0;

        /**
         * @brief send packet via TCP
         *
         * @param packet packet to be send
         * @param socket_id socket id
         */
        virtual void sendTCPData(Packet &packet, std::size_t const &socket_id) = 0;

    // @MARK Methods
        public:
        /**
         * @brief Stop the network process
         */
        virtual void stop(void) = 0;

        /**
         * @brief Run the network process in main thread
         */
        virtual void run(void) = 0;

        /**
         * @brief Run the network process in an other thread
         */
        virtual void async_run(void) = 0;
    };

}

#endif /* !CPP_RTYPE_2019_I_NETWORK_HPP */
