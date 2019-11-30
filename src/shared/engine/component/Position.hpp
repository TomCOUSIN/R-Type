/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_POSITION_HPP
#define CPP_RTYPE_2019_POSITION_HPP

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
        explicit Position(float const &x = 0.0f, float const &y = 0.0f, bool is_centered = false) : x(x), y(y), is_centered(is_centered) {}

        /**
         * @brief The x value of the Position
         */
        float x;

        /**
         * @brief The y value of the Position
         */
        float y;

        /**
         * @brief If the position is centered
         */
        float is_centered;

        /**
         * @brief The type of the Component Position
         */
        static const engine::component::ComponentType type = 1 << COMPONENT_TYPE::POSITION;
    };
}

#endif //CPP_RTYPE_2019_POSITION_HPP
