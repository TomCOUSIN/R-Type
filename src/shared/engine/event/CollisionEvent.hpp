/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef COLLISIONEVENT_HPP_
#define COLLISIONEVENT_HPP_

#include <unordered_map>

#include "Event.hpp"
#include "Collision.hpp"
#include "Entity.hpp"

namespace rtype::engine::event {

    class CollisionEvent : public engine::event::Event {

    // @MARK Types
        public:
        enum CollisionEventType : engine::event::EventType {
            BEGIN_COLLIDE,
            END_COLLIDE,
        };


    // @MARK Constructors/Destructors
        public:
        /**
         * @brief Construct a new Collision Event
         */
        CollisionEvent(CollisionEventType event_type, engine::entity::Entity entity, component::Collision::IdType component_type);

        /**
         * @brief Construct a new Collision Event
         */
        CollisionEvent(CollisionEventType event_type, component::Collision::IdType id);

        /**
         * @brief Destroy the Collision Event
         */
        ~CollisionEvent() = default;

    };

}

#endif /* !COLLISIONEVENT_HPP_ */
