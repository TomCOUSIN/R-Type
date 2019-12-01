/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_HEALTH_HPP
#define CPP_RTYPE_2019_HEALTH_HPP

#include "Component.hpp"

namespace rtype::engine::component {

    /**
     * @brief Health Component to handle health
     */
    struct Health : public engine::component::Component {

        /**
         * @brief Construct a new Health Component
         *
         * @param value The value of the health
         */
        explicit Health(int const &value) :
        health(value), isDead(false) {}

        /**
         * @brief The health value
         */
        int health;

        /**
         * @brief boolean to know if an Entity is dead
         */
        bool isDead;

        /**
         * @brief When an entity die
         */
        void onDeath() {
            isDead = true;
        }

        /**
         * @brief The type of the Component Health
         */
        static const engine::component::ComponentType type = 1 << COMPONENT_TYPE::HEALTH;
    };
}

#endif //CPP_RTYPE_2019_HEALTH_HPP
