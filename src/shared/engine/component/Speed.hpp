/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SPEED_HPP
#define CPP_RTYPE_2019_SPEED_HPP

#include <SFML/Graphics.hpp>
#include "Component.hpp"

namespace rtype::engine::component {

    /**
     * @brief Component Speed to handle Speed values of Entity
     */
    struct Speed : public engine::component::Component {

        /**
         * @brief Construct a Speed Component
         *
         * @param x The x value of the Speed
         * @param y The y value of the Speed
         */
        explicit Speed(float const &x = 1.0f, float const &y = 1.0f) : x(x), y(y) {}

        /**
         * @brief The x value of the Speed
         */
        float x;

        /**
         * @brief The y value of the Speed
         */
        float y;

        /**
         * @brief The type of the Component Position
         */
        static const engine::component::ComponentType type = 3;
    };
}

#endif //CPP_RTYPE_2019_SPEED_HPP
