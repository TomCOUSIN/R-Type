/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_BUTTONSYSTEM_HPP
#define CPP_RTYPE_2019_BUTTONSYSTEM_HPP

#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"
#include "Position.hpp"
#include "ISystem.hpp"
#include "Button.hpp"

namespace rtype {

    namespace sfml {

        namespace system {

            /**
             * @brief Handle Button onHover, onDisplay
             */
            class ButtonSystem : public engine::system::ISystem {

                public:
                /**
                 * @brief Construct a ButtonSystem object
                 *
                 * @param engine The engine to use
                 * @param window The window to use to catch mouse position
                 */
                ButtonSystem(engine::GameEngine &engine, sf::RenderWindow &window);

                /**
                 * @brief Destroy a ButtonSystem object
                 */
                ~ButtonSystem() final = default;

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
                 * @brief Check if the mouse is on the button or not
                 *
                 * @param position The mouse position
                 * @param button The Button to check
                 */
                void checkButtonDisplay(component::Button *button, component::Position *button_position);

                /**
                 * @brief Check if the mouse click on the button or not
                 *
                 * @param position The mouse position
                 * @param button The Button to check
                 */
                void checkButtonPressed(component::Button *button, component::Position *button_position);

                /**
                 * @brief The SystemType of the InputSystem
                 */
                static const engine::system::SystemType type = 2;

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

#endif //CPP_RTYPE_2019_BUTTONSYSTEM_HPP
