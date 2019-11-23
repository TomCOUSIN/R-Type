/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_COMPONENT_HPP
#define CPP_RTYPE_2019_COMPONENT_HPP

namespace rtype {

    namespace engine {

        namespace component {

            /**
             * @brief Enum to define all the Component's type
             */
            enum ComponentType {
                INVALID = 0,
                POSITION = 1,
                SPEED = 2
            };

            /**
             * @brief A basic Component
             */
            struct Component {

                /**
                 * @brief Component's type.
                 *
                 * By default it is set to INVALID
                 */
                static const ComponentType type = INVALID;
            };
        }
    }
}
#endif //CPP_RTYPE_2019_COMPONENT_HPP
