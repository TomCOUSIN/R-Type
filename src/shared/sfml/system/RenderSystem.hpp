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
#include "Position.hpp"

namespace rtype {

    namespace sfml {

        namespace system {

            /**
             * @brief The SFML RenderSystem to display sprites
             */
            class RenderSystem : public engine::system::ISystem {

                public:
                /**
                 * @brief Construct a new RenderSystem
                 */
                RenderSystem(engine::GameEngine &engine, sf::RenderWindow &window);

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
                 * @brief Render Sprite
                 */
                void renderSprite(engine::entity::Entity const &entity);

                /**
                 * @brief Render Button
                 */
                void renderButton(engine::entity::Entity const &entity);

                /**
                 * @brief Render Text
                 */
                void renderText(engine::entity::Entity const &entity);

                /**
                 * @brief The SystemType of the RenderSystem
                 *
                 * @param entity The entity to draw
                 */
                static const engine::system::SystemType type = 7;

                private:
                /**
                 * @brief The window used to catch event
                 */
                sf::RenderWindow &_window;

                /**
                 * @brief The engine to use to get Sprite Component
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

#endif //CPP_RTYPE_2019_RENDERSYSTEM_HPP
