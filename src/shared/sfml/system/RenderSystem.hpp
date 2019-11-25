/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_RENDERSYSTEM_HPP
#define CPP_RTYPE_2019_RENDERSYSTEM_HPP

#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"
#include "ISystem.hpp"

namespace rtype {

    namespace engine {

        namespace system {

            /**
             * @brief The SFML RenderSystem to display sprites
             */
            class RenderSystem : public ISystem {

                public:
                /**
                 * @brief Construct a new RenderSystem
                 */
                RenderSystem(GameEngine &engine, sf::RenderWindow &window);

                /**
                 * @brief Destroy a RenderSystem object
                 */
                ~RenderSystem() final = default;

                /**
                 * @brief Update all Sprite according to Position
                 *
                 * @param delta The deltatime since last update
                 */
                void update(float const &delta) final;

                private:
                /**
                 * @brief The window used to catch event
                 */
                sf::RenderWindow &_window;

                /**
                 * @brief The engine to use to get Sprite Component
                 */
                GameEngine &_engine;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_RENDERSYSTEM_HPP
