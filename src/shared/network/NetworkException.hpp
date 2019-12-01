/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Created by lucasmrdt
*/

#ifndef CPP_BABEL_2019_NETWORKEXCEPTION_HPP
#define CPP_BABEL_2019_NETWORKEXCEPTION_HPP

#include "BaseException.hpp"

namespace rtype::network {

    class NetworkException : public exception::BaseException {

        // @MARK Constructor and destructor
        public:
        explicit NetworkException(const std::string &message):
            BaseException(message, "NetworkException")
        {}

        // @MARK Operators
        public:
		NetworkException &operator=(const NetworkException &) = delete;

    };

}

#endif /* !CPP_BABEL_2019_NETWORKEXCEPTION_HPP */
