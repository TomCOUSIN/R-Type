/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_ENEMYSYSTEM_HPP
#define CPP_RTYPE_2019_ENEMYSYSTEM_HPP

#include "SpriteEntity.hpp"
#include "GameEngine.hpp"
#include "ISystem.hpp"

namespace rtype::sfml::system {

    class EnemySystem : public rtype::engine::system::ISystem {

        public:
        /**
         * @brief Construct a new EnemySystem object
         *
         * @param engine The GameEngine to use to create Enemy
         */
        EnemySystem(engine::GameEngine &engine);

        /**
         * @brief Destroy an EnemySystem object
         */
        ~EnemySystem() final = default;

        /**
         * @brief Update all the Enemy
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
         * @brief Spawn an Enemy
         */
        void spawnEnemy();

        /**
         * @brief The SystemType of the InputSystem
         */
        static const engine::system::SystemType type = 1 << engine::system::SYSTEM_TYPE::ENEMY;

        private:
        /**
         * @brief The engine to use to set EVENT
         */
        engine::GameEngine &_engine;

        /**
         * @brief The vector of enemy
         */
        std::vector<std::shared_ptr<sfml::entity::SpriteEntity>> _enemys;
    };
}

#endif //CPP_RTYPE_2019_ENEMYSYSTEM_HPP
