/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_ENEMYENTITY_HPP
#define CPP_RTYPE_2019_ENEMYENTITY_HPP

#include <memory>
#include <iostream>
#include "EntityCreator.hpp"
#include "Position.hpp"

namespace rtype::sfml::entity {

    /**
     * @brief BulletEntity
     */
    class EnemyEntity : public engine::entity::EntityCreator {

        public:
        /**
         * @brief Construct a new SpriteEntity Entity
         */
        EnemyEntity(engine::GameEngine &engine,
            std::string const &texture_path
            , float const &x
            , float const &y
            , float const &width
            , float const &height
            , float const &scale_width
            , float const &scale_height);

        /**
         * @brief Get the Entity of the Sprite
         * @return
         */
        engine::entity::Entity getEnemyEntity() const;

        /**
         * @brief When the Enemy is colliding
         */
        void onCollision(engine::event::Event const &event);

        /**
         * @brief The type of the Created Entity
         */
        static const engine::entity::EntityType type;

        private:
        /**
         * @brief The Entity of the Sprite
         */
        engine::entity::Entity _enemy_entity;

        /**
         * @brief The position of the Sprite
         */
        std::shared_ptr <engine::component::Position> _position;
    };
}

#endif //CPP_RTYPE_2019_ENEMYENTITY_HPP
