/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_INPUTSYSTEM_HPP
#define CPP_RTYPE_2019_INPUTSYSTEM_HPP

#include <SFML/Graphics.hpp>
#include "ISystem.hpp"

namespace rtype {

    namespace engine {

        namespace system {

            /**
             * @brief An InputSystem to handle Event
             */
            class InputSystem : public ISystem {

                public:
                /**
                 * @brief Construct a new InputSystem object
                 *
                 * @param window The sf::Window to use to catch input
                 */
                InputSystem(sf::Window &window);

                /**
                 * @brief Destroy an InputSystem object
                 */
                ~InputSystem() final = default;

                /**
                 * @brief Update sf::Event according to the sf::Window
                 *
                 * @param delta The deltatime since last update
                 */
                void update(float const &delta) final;

                private:
                /**
                 * @brief The window used to catch event
                 */
                sf::Window &_window;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_INPUTSYSTEM_HPP
