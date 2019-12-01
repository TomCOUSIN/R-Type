/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_ISYSTEM_HPP
#define CPP_RTYPE_2019_ISYSTEM_HPP

#include "Entity.hpp"

namespace rtype {

    namespace engine {

        namespace system {

            /**
             * @brief typedef SystemType to identify ISystem
             */
            typedef unsigned long SystemType;

            /**
             * @brief enum SYSTEM_TYPE
             */
            enum SYSTEM_TYPE {
                ANIMATION,
                BUTTON,
                INPUT,
                BULLET,
                PARALLAX,
                POSITION,
                COLLISION,
                RENDER,
            };

            /**
             * @brief Interface for all System of the GameEngine
             */
            class ISystem {

                public:
                /**
                 * @brief Destructor of the System
                 */
                virtual ~ISystem() = default;

                /**
                 * @brief Update Entity Component linked to the ISystem
                 *
                 * @param delta The deltatime between 2 frame
                 */
                virtual void update(float const &delta) = 0;

                /**
                 * @brief Add an Entity to the ISystem
                 * @param entity The Entity to add
                 */
                virtual void addEntity(entity::Entity const &entity) = 0;

                /**
                 * @brief Remove an Entity from the ISystem
                 * @param entity The Entity to remove
                 */
                virtual void removeEntity(entity::Entity const &entity) = 0;

                /**
                 * @brief The SystemType of the ISystem
                 */
                static const SystemType type = 0;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_ISYSTEM_HPP
