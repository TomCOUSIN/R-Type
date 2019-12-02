/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** ForkException.hpp
*/

#ifndef CPP_rtype_2019_FORKEXCEPTION_HPP
#define CPP_rtype_2019_FORKEXCEPTION_HPP

#include "BaseException.hpp"

namespace rtype::encapsulation {

    class ForkException : public exception::BaseException {

        // -
        public:
		ForkException &operator=(const ForkException &) = delete;

        // Constructor and destructor.
        public:
        explicit ForkException(const std::string &message):
            BaseException(message, "ForkException")
        {}

    };

}

#endif /* !CPP_rtype_2019_FORKEXCEPTION_HPP */
