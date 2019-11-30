/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by lucasmrdt
*/

#ifndef CPP_RTYPE_2019_COLLISIONSYSTEM_HPP
#define CPP_RTYPE_2019_COLLISIONSYSTEM_HPP

#include <unordered_set>

#include "GameEngine.hpp"
#include "Position.hpp"
#include "ISystem.hpp"
#include "Collision.hpp"

namespace rtype::engine::system {

    /**
     * @brief Handle Collision
     */
    class CollisionSystem : public engine::system::ISystem {

    // @MARK Types
        public:
        struct Rect {
            float left;
            float top;
            float right;
            float bottom;
        };

    // @MARK Constructors/Destructors
        public:
        /**
         * @brief Construct a CollisionSystem object
         *
         * @param engine The engine to use
         * @param window The window to use to catch mouse position
         */
        CollisionSystem(engine::GameEngine &engine);

        /**
         * @brief Destroy a CollisionSystem object
         */
        ~CollisionSystem() final = default;

    // @MARK Methods
        public:
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

        private:
        void checkCollision(engine::entity::Entity const &entity
                           , std::shared_ptr<component::Collision> collision_a
                           , std::shared_ptr<component::Position> position_a
                           , std::shared_ptr<component::Collision> collision_b
                           , std::shared_ptr<component::Position> position_b);

        CollisionSystem::Rect getRect(std::shared_ptr<component::Collision> collision, std::shared_ptr<component::Position> position) const;

    // @MARK Static
        public:
        /**
         * @brief The SystemType of the InputSystem
         */
        static const engine::system::SystemType type = 1 << SYSTEM_TYPE::COLLISION;


    // @MARK Properties
        private:
        /**
         * @brief The engine to use to set EVENT
         */
        engine::GameEngine &_engine;

        /**
         * @brief The vector of Entity
         */
        std::vector<engine::entity::Entity> _entities;

        /**
         * @brief The vector of Entity
         */
        std::unordered_set<component::Collision::IdType> _previous_collisions;
        std::unordered_set<component::Collision::IdType> _current_collisions;
    };
}

#endif //CPP_RTYPE_2019_COLLISIONSYSTEM_HPP
