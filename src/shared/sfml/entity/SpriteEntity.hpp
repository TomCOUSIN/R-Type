/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SPRITEENTITY_HPP
#define CPP_RTYPE_2019_SPRITEENTITY_HPP

#include <memory>
#include <iostream>
#include "EntityCreator.hpp"
#include "Position.hpp"
#include "Speed.hpp"

namespace rtype::sfml::entity {

    class SpriteEntity : public engine::entity::EntityCreator {

        public:
        /**
         * @brief Construct a new SpriteEntity Entity
         */
        SpriteEntity(engine::GameEngine &engine
            , std::string const &texture_path
            , float const &x
            , float const &y
            , float const &width
            , float const &height
            , float const &scale_width
            , float const &scale_height
            , size_t const &sprite_count
            , bool const &movable = false
            , float const &speed_x = 1.0f
            , float const &speed_y = 1.0f);

        /**
         * @brief Get the Entity of the Sprite
         * @return
         */
        engine::entity::Entity getSpriteEntity() const;

        /**
         * @brief When the arrow up key is pressed
         */
        void onArrowUpPressed(engine::event::Event const &event);

        /**
         * @brief When the arrow up key is pressed
         */
        void onArrowDownPressed(engine::event::Event const &event);

        /**
         * @brief When the arrow up key is pressed
         */
        void onArrowLeftPressed(engine::event::Event const &event);

        /**
         * @brief When the arrow up key is pressed
         */
        void onArrowRightPressed(engine::event::Event const &event);

        /**
         * @brief The type of the Created Entity
         */
        static const engine::entity::EntityType type;

        private:
        /**
         * @brief The Entity of the Sprite
         */
        engine::entity::Entity _sprite_entity;

        /**
         * @brief The postition of the Sprite
         */
        std::shared_ptr<engine::component::Position> _position;

        /**
         * @brief The speed of the Sprite
         */
        std::shared_ptr<engine::component::Speed> _speed;
    };
}

#endif //CPP_RTYPE_2019_SPRITEENTITY_HPP
