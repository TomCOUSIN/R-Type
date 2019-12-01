/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by lucasmrdt
*/

#ifndef CPP_RTYPE_2019_COLLISION_HPP
#define CPP_RTYPE_2019_COLLISION_HPP

#include "Component.hpp"

namespace rtype::engine::component {

    /**
     * @brief Collision Component to handle collision
     */
    struct Collision : public engine::component::Component {

    // @MARK Types
        using IdType = unsigned long long;

    // @MARK Constructors/Destructors
        /**
         * @brief Construct a new Collision Component
         *
         * @param width The width value of the Collision
         * @param height The height value of the Collision
         */
        explicit Collision(float const &width, float const &height, IdType const &id) : width(width), height(height), id(id) {}

        /**
         * @brief The width value of the Collision
         */
        float width;

        /**
         * @brief The height value of the Collision
         */
        float height;

        /**
         * @brief The linked id of the Collision
         */
        IdType id;

        /**
         * @brief The type of the Component Collision
         */
        static const engine::component::ComponentType type = 1 << COMPONENT_TYPE::COLLISION;
    };
}

#endif //CPP_RTYPE_2019_COLLISION_HPP
