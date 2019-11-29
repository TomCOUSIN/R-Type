/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_MOVEMENTSYSTEM_HPP
#define CPP_RTYPE_2019_MOVEMENTSYSTEM_HPP

#include "GameEngine.hpp"
#include "Position.hpp"
#include "ISystem.hpp"
#include "Speed.hpp"

namespace rtype {

    namespace sfml {

        namespace system {

            /**
             * @brief SFML MovementSystem to move Entity according to the EVENT
             */
            class MovementSystem : public engine::system::ISystem {

                public:
                /**
                 * @brief Construct a MovementSystem
                 *
                 * @param engine The GameEngine to use
                 */
                MovementSystem(engine::GameEngine &engine);

                /**
                 * @brief Destroy a GameEngine
                 */
                ~MovementSystem() final = default;

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
                static const engine::system::SystemType type = 3;

                private:

                /**
                 * @brief Change Position value to go up
                 *
                 * @param position The Position to change
                 */
                void moveUp(engine::component::Position *position, engine::component::Speed *speed);

                /**
                 * @brief Change Position value to go down
                 *
                 * @param position The Position to change
                 */
                void moveDown(engine::component::Position *position, engine::component::Speed *speed);

                /**
                 * @brief Change Position value to go right
                 *
                 * @param position The Position to change
                 */
                void moveRight(engine::component::Position *position, engine::component::Speed *speed);

                /**
                 * @brief Change Position value to go left
                 *
                 * @param position The Position to change
                 */
                void moveLeft(engine::component::Position *position, engine::component::Speed *speed);

                /**
                 * @brief Change Position value to go left
                 *
                 * @param position The Position to change
                 */
                void moveSprite(component::Position *position, component::Speed *speed);

                /**
                 * @brief The GameEngine to use to get EVENT and Component
                 */
                engine::GameEngine &_engine;

                /**
                 * @brief The vector of Entity
                 */
                std::vector<engine::entity::Entity> _entities;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_MOVEMENTSYSTEM_HPP
