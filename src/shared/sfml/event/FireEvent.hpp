/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_FIREEVENT_HPP
#define CPP_RTYPE_2019_FIREEVENT_HPP

#include "Position.hpp"
#include "Entity.hpp"
#include "Event.hpp"

namespace rtype::sfml::event {

    class FireEvent : public engine::event::Event {

        public:
        /**
         * @brief Enum to describe which Entity is firing
         */
        enum FireEventType : engine::event::EventType {
            ALLY,
            ENNEMY,
        };

        /**
         * @brief Construct a new FireEvent Event
         */
        explicit FireEvent(FireEventType event_type);

        /**
         * @brief Construct a new FireEvent Event
         */
        explicit FireEvent(FireEventType event_type, std::shared_ptr<engine::component::Position> position);

        /**
         * @brief Destroy the FireEvent Event
         */
        ~FireEvent() final = default;
    };

}

#endif //CPP_RTYPE_2019_FIREEVENT_HPP
