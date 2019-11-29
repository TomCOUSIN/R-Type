/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_POSITION_HPP
#define CPP_RTYPE_2019_POSITION_HPP

#include <SFML/Graphics.hpp>
#include "Component.hpp"

namespace rtype::engine::component {

    /**
     * @brief Position Component to handle position
     */
    struct Position : public engine::component::Component {

        /**
         * @brief Construct a new Position Component
         *
         * @param x The x value of the Position
         * @param y The y value of the Position
         */
        explicit Position(float const &x = 0.0f, float const &y = 0.0f) : x(x), y(y) {}

        /**
         * @brief The x value of the Position
         */
        float x;

        /**
         * @brief The y value of the Position
         */
        float y;

        /**
         * @brief The type of the Component Position
         */
        static const engine::component::ComponentType type = 1;
    };
}

#endif //CPP_RTYPE_2019_POSITION_HPP
