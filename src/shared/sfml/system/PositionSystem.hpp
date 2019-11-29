/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_POSITIONSYSTEM_HPP
#define CPP_RTYPE_2019_POSITIONSYSTEM_HPP

#include <GameEngine.hpp>
#include "Position.hpp"
#include "ISystem.hpp"

namespace rtype::sfml::system {

    /**
     * @brief PositionSystem to update Sprite with Position
     */
    class PositionSystem : public engine::system::ISystem {

        public:
        /**
         * @brief Construct a PositionSystem object
         *
         * @param engine The GameEngine to use
         */
        explicit PositionSystem(engine::GameEngine &engine);
        ~PositionSystem() final = default;

        /**
         * @brief Update the Sprite with Position value
         * @param delta
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
         * @brief Update the Sprite Position
         *
         * @param entity The entity to update
         */
        void updateSpritePosition(engine::component::Position *position, engine::entity::Entity const &entity);

        /**
         * @brief Update the Button Position
         *
         * @param entity The entity to update
         */
        void updateButtonPosition(engine::component::Position *position, engine::entity::Entity const &entity);

        /**
         * @brief Update the Text Position
         *
         * @param entity The entity to update
         */
        void updateTextPosition(engine::component::Position *position, engine::entity::Entity const &entity);

        /**
         * @brief The SystemType of the PositionSystem
         */
        static const engine::system::SystemType type = 4;

        private:

        /**
         * @brief The GameEngine to use
         */
        engine::GameEngine &_engine;

        /**
         * @brief The vector of Entity
         */
        std::vector<engine::entity::Entity> _entities;
    };
}

#endif //CPP_RTYPE_2019_POSITIONSYSTEM_HPP
