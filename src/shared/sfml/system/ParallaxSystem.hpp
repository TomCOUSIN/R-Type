/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_PARALLAXSYSTEM_HPP
#define CPP_RTYPE_2019_PARALLAXSYSTEM_HPP

#include "GameEngine.hpp"
#include "ISystem.hpp"

namespace rtype::sfml::system {

    /**
     * @brief The SFML ParallaxSystem to display parallax
     */
    class ParallaxSystem : public engine::system::ISystem {

        public:
        /**
         * @brief Construct a new ParallaxSystem
         */
        explicit ParallaxSystem(engine::GameEngine &engine);

        /**
         * @brief Destroy a ParallaxSystem object
         */
        ~ParallaxSystem() final = default;

        /**
         * @brief Update all Sprite according to Position and Speed
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
         * @brief The SystemType of the ParallaxSystem
         */
        static const engine::system::SystemType type = 1 << engine::system::SYSTEM_TYPE::PARALLAX;

        private:
        /**
         * @brief The engine to use to set parallax
         */
        engine::GameEngine &_engine;

        /**
         * @brief The vector of Entity
         */
        std::vector<engine::entity::Entity> _entities;
    };
}

#endif //CPP_RTYPE_2019_PARALLAXSYSTEM_HPP
