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

namespace rtype {

    namespace sfml {

        namespace component {

            /**
             * @brief Component Speed to handle Speed values of Entity
             */
            struct Speed : public engine::component::Component {

                /**
                 * @brief Construct a Speed Component
                 *
                 * @param speed The Speed value
                 */
                explicit Speed(size_t const &speed = 1) : speed(speed) {}

                /**
                 * @brief Vector that contain Speed value
                 */
                size_t speed;

                /**
                 * @brief The type of the Component Position
                 */
                static const engine::component::ComponentType type = 3;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_SPEED_HPP
