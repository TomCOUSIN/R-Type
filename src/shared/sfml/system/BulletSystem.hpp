/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_BULLETSYSTEM_HPP
#define CPP_RTYPE_2019_BULLETSYSTEM_HPP

#include <memory>
#include <vector>
#include <iostream>
#include "SpriteEntity.hpp"
#include "BulletEntity.hpp"
#include "GameEngine.hpp"
#include "InputEvent.hpp"
#include "ISystem.hpp"

namespace rtype::sfml::system {

    class BulletSystem : public engine::system::ISystem {

        public:
        /**
         * @brief Construct a BulletSystem object
         *
         * @param engine The engine to use
         */
        explicit BulletSystem(engine::GameEngine &engine);

        /**
         * @brief Destroy a BulletSystem object
         */
        ~BulletSystem() final = default;

        /**
         * @brief Update all bullets
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
         * @brief Add a bullet to the list of bullets
         */
        void addBullet(const rtype::engine::event::Event &event);

        /**
         * @brief The SystemType of the InputSystem
         */
        static const engine::system::SystemType type = 1 << engine::system::SYSTEM_TYPE::BULLET;

        private:
        /**
         * @brief The engine to use
         */
        engine::GameEngine &_engine;

        /**
         * @brief The vector of bullets
         */
        std::vector<std::shared_ptr<sfml::entity::BulletEntity>> _bullets;
    };
}

#endif //CPP_RTYPE_2019_BULLETSYSTEM_HPP
