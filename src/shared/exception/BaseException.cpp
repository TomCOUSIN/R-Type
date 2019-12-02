/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** BaseException.cpp
*/

#include "BaseException.hpp"

// using namespace rtype::exception;

namespace rtype::exception {

BaseException::BaseException(std::string const &message, const std::string &component):
    _message(message),
    _component(component)
{}

const std::string &
BaseException::getComponent(void) const
{
    return _component;
}

const char *
BaseException::what(void) const noexcept
{
    return _message.data();
}

}

