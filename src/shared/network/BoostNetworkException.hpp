/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostNetworkException.hpp
*/

#ifndef CPP_BABEL_2019_BOOSTNETWORKEXCEPTION_HPP
#define CPP_BABEL_2019_BOOSTNETWORKEXCEPTION_HPP

#include "BaseException.hpp"

namespace rtype::network {

    class BoostNetworkException : public exception::BaseException {

        // -
        public:
		BoostNetworkException &operator=(const BoostNetworkException &) = delete;

        // Constructor and destructor.
        public:
        explicit BoostNetworkException(const std::string &message):
            BaseException(message, "BoostNetworkException")
        {}

    };

}

#endif /* !CPP_BABEL_2019_BOOSTNETWORKEXCEPTION_HPP */
