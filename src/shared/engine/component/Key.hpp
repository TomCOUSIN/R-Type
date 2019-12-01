/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by lucasmrdt,
*/

#ifndef CPP_RTYPE_2019_KEY_HPP
#define CPP_RTYPE_2019_KEY_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Component.hpp"

namespace rtype::engine::component {
    /**
     * @brief a Key Component
     */
    struct Key : public engine::component::Component {

        /**
         * @brief Construct a Key Component
         *
         * @param width The width of the Key
         * @param height The height of the Key
         */
        Key(char value) :
        value(value) {}

        /**
         * @brief The value of key
         */
        char value;

        /**
         * @brief The type of the Component Key
         */
        static const engine::component::ComponentType type = 1 << engine::component::COMPONENT_TYPE::KEY;
    };
}

#endif //CPP_RTYPE_2019_KEY_HPP
