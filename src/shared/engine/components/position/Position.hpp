/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_POSITION_HPP
#define CPP_RTYPE_2019_POSITION_HPP

#include "Component.hpp"

namespace rtype {

    namespace engine {

        namespace component {

            /**
             * @brief A Component that handle the Position
             */
            struct Position : public Component {

                /**
                 * @brief Constructor of the Component Position
                 *
                 * @param x The x value
                 * @param y The y value
                 */
                explicit Position(float const &x = 0.0f, float const &y = 0.0f) : x(x), y(y) {};

                /**
                 * @brief The x value of the Position
                 */
                float x;

                /**
                 * @brief The y value of the Position
                 */
                float y;

                /**
                 * @brief The ComponentType of the Component
                 */
                static const ComponentType type = POSITION;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_POSITION_HPP
