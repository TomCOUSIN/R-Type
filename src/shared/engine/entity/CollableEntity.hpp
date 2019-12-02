/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_COLLABLE_ENTITY_HPP
#define CPP_RTYPE_2019_COLLABLE_ENTITY_HPP

#include <memory>
#include <iostream>
#include "EntityCreator.hpp"
#include "Position.hpp"
#include "Speed.hpp"

namespace rtype::engine::entity {

    class CollableEntity : public EntityCreator {

    // @MARK Constructors/Destructors
        public:
        /**
         * @brief Construct a new CollableEntity Entity
         */
        CollableEntity(engine::GameEngine &engine
            , float const &x
            , float const &y
            , float const &width
            , float const &height
            , float const &speed_x = 1.0f
            , float const &speed_y = 1.0f);

    // @MARK Getters
        public:
        /**
         * @brief Get the Entity of the Sprite
         * @return
         */
        engine::entity::Entity getCollableEntity() const;

        std::shared_ptr<engine::component::Position> getPosition(void) { return _position; }

        std::shared_ptr<engine::component::Speed> getSpeed(void) { return _speed; }

    // @MARK Handlers
        private:
        /**
         * @brief The type of the Created Entity
         */
        static const engine::entity::EntityType type;

        private:
        /**
         * @brief The Entity of the Sprite
         */
        engine::entity::Entity _collable_entity;

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

#endif //CPP_RTYPE_2019_COLLABLE_ENTITY_HPP
