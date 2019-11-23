/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SPEED_HPP
#define CPP_RTYPE_2019_SPEED_HPP

#include "Component.hpp"

namespace rtype {

    namespace engine {

        namespace component {

            /**
             * @brief A Component that handle the Speed
             */
            struct Speed : public Component {

                /**
                 * @brief Constructor of the Component Speed
                 *
                 * @param x The x value
                 * @param y The y value
                 */
                explicit Speed(float const &x = 0.0f, float const &y = 0.0f) : x(x), y(y) {};

                /**
                 * @brief The x value of the Speed
                 */
                float x;

                /**
                 * @brief The y value of the Speed
                 */
                float y;

                /**
                 * @brief The ComponentType of the Component
                 */
                static const ComponentType type = SPEED;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_SPEED_HPP
