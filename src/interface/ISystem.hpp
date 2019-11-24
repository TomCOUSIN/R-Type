/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_ISYSTEM_HPP
#define CPP_RTYPE_2019_ISYSTEM_HPP

namespace rtype {

    namespace engine {

        namespace system {

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
            };
        }
    }
}

#endif //CPP_RTYPE_2019_ISYSTEM_HPP
