/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** BoostNetworkException.hpp
*/

#ifndef CPP_rtype_2019_BOOSTNETWORKEXCEPTION_HPP
#define CPP_rtype_2019_BOOSTNETWORKEXCEPTION_HPP

#include "NetworkException.hpp"
#include "BaseException.hpp"

namespace rtype::network {

    class BoostNetworkException : public NetworkException {

        // -
        public:
		BoostNetworkException &operator=(const BoostNetworkException &) = delete;

        // Constructor and destructor.
        public:
        explicit BoostNetworkException(const std::string &message):
            NetworkException(message)
        {}

    };

}

#endif /* !CPP_rtype_2019_BOOSTNETWORKEXCEPTION_HPP */
