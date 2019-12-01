/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_ANIMATIONSYSTEM_HPP
#define CPP_RTYPE_2019_ANIMATIONSYSTEM_HPP

#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"
#include "ISystem.hpp"

namespace rtype {

    namespace sfml {

        namespace system {

            /**
             * @brief AnimationSystem to animate SpriteSheet
             */
            class AnimationSystem : public engine::system::ISystem {

                public:
                /**
                 * @brief Construct an AnimationEngine ISystem
                 *
                 * @param engine The GameEngine to use
                 */
                AnimationSystem(engine::GameEngine &engine);

                /**
                 * @brief Destroy an AnimationSystem
                 */
                ~AnimationSystem() final = default;

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
                 * @brief The SystemType of the AnimationSystem
                 */
                static const engine::system::SystemType type = 1 << engine::system::SYSTEM_TYPE::ANIMATION;

                private:
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

#endif //CPP_RTYPE_2019_ANIMATIONSYSTEM_HPP
