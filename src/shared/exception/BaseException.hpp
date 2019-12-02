/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** BaseException.hpp
*/

#ifndef CPP_rtype_2019_BASEEXCEPTION_HPP
#define CPP_rtype_2019_BASEEXCEPTION_HPP

#include <iostream>

namespace rtype::exception {

    class BaseException : public std::exception {

        // @MARK Operators
        public:
		BaseException &operator=(const BaseException &) = delete;

        // @MARK Constructor and destructor
        public:
        explicit BaseException(std::string const &message, const std::string &component);

        // @MARK Methods
        public:
        const std::string &getComponent(void) const;
        const char *what(void) const noexcept override;

        // @MARK Attributes
        private:
        std::string _message;
        std::string _component;

    };

}

#endif /* !CPP_rtype_2019_BASEEXCEPTION_HPP */
