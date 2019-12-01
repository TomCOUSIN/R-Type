/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_INPUTSYSTEM_HPP
#define CPP_RTYPE_2019_INPUTSYSTEM_HPP

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"
#include "ISystem.hpp"
#include "Entity.hpp"

namespace rtype {

    namespace sfml {

        namespace system {

            /**
             * @brief An InputSystem to handle Event
             */
            class InputSystem : public engine::system::ISystem {

                public:
                /**
                 * @brief Construct a new InputSystem object
                 *
                 * @param window The sf::Window to use to catch input
                 */
                InputSystem(engine::GameEngine &engine, sf::RenderWindow &window);

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

                /**
                 * @brief Add an Entity to the ISystem
                 *
                 * @param entity The Entity to add
                 */
                void addEntity(engine::entity::Entity const &entity) final;

                /**
                 * @brief Remove an Entity from the ISystem
                 *
                 * @param entity The Entity to remove
                 */
                void removeEntity(engine::entity::Entity const &entity) final;

                /**
                 * @brief The SystemType of the InputSystem
                 */
                static const engine::system::SystemType type = 1 << engine::system::SYSTEM_TYPE::INPUT;

                private:
                /**
                 * @brief The engine to use to set EVENT
                 */
                engine::GameEngine &_engine;

                /**
                 * @brief The window used to catch event
                 */
                sf::RenderWindow &_window;

                /**
                 * @brief The vector of Entity
                 */
                std::vector<engine::entity::Entity> _entities;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_INPUTSYSTEM_HPP
