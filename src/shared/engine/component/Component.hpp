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
             * @brief Define the ComponentType
             */
            typedef unsigned long ComponentType;

            /**
             * @brief enum COMPONENT_TYPE
             */
            enum COMPONENT_TYPE {
                COLLISION,
                HEALTH,
                POSITION,
                SPEED,
                BUTTON,
                SPRITE,
                TEXT,
                SOUND,
                MUSIC,
            };

            /**
             * @brief A basic Component
             */
            struct Component {

                /**
                 * @brief Destroy the Component
                 */
                virtual ~Component() = default;

                /**
                 * @brief Component's type.
                 *
                 * By default it is set to INVALID
                 */
                static const ComponentType type = 0;
            };
        }
    }
}
#endif //CPP_RTYPE_2019_COMPONENT_HPP
