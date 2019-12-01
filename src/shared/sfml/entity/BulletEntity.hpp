/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_BULLETENTITY_HPP
#define CPP_RTYPE_2019_BULLETENTITY_HPP

#include <memory>
#include <iostream>
#include "EntityCreator.hpp"
#include "Position.hpp"
#include "Speed.hpp"

namespace rtype::sfml::entity {

    /**
     * @brief BulletEntity
     */
    class BulletEntity : public engine::entity::EntityCreator {

        public:
        /**
         * @brief Construct a new SpriteEntity Entity
         */
        BulletEntity(engine::GameEngine &engine,
            std::string const &texture_path
            , float const &x
            , float const &y
            , float const &width
            , float const &height
            , float const &scale_width
            , float const &scale_height
            , size_t const &sprite_count
            , int const &direction);

        /**
         * @brief Get the Entity of the Sprite
         * @return
         */
        engine::entity::Entity getBulletEntity() const;

        /**
         * @brief When the Bullet is colliding
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
        engine::entity::Entity _bullet_entity;

        /**
         * @brief The position of the Sprite
         */
        std::shared_ptr <engine::component::Position> _position;

        /**
         * @brief The speed of the Sprite
         */
        std::shared_ptr <engine::component::Speed> _speed;
    };
}

#endif //CPP_RTYPE_2019_BULLETENTITY_HPP
