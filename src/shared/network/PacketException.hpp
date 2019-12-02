/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Created by lucasmrdt
*/

#ifndef CPP_rtype_2019_PACKETEXCEPTION_HPP
#define CPP_rtype_2019_PACKETEXCEPTION_HPP

#include "BaseException.hpp"

namespace rtype::network {

    class PacketException : public exception::BaseException {

        // @MARK Constructor and destructor
        public:
        explicit PacketException(const std::string &message):
            BaseException(message, "PacketException")
        {}

        // @MARK Operators
        public:
		PacketException &operator=(const PacketException &) = delete;

    };

}

#endif /* !CPP_rtype_2019_PACKETEXCEPTION_HPP */
