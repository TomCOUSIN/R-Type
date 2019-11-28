/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_EVENT_HPP
#define CPP_RTYPE_2019_EVENT_HPP

#include <iostream>
#include "IEvent.hpp"
#include "Component.hpp"

namespace rtype::engine::event {

    /**
     * @brief Event class to handle GameEngine event
     */
    class Event : public IEvent {

        public:
        /**
         * @brief Construct an Event object
         */
        Event(EVENT_SENDER sender, EVENT_TYPE event_type, std::shared_ptr<component::Component> data = nullptr);

        /**
         * @brief Destroy an Event object
         */
        ~Event() final = default;

        /**
         * @brief Get the sender of the Event
         *
         * @return The sender of the Event
         */
        EVENT_SENDER getSender() const;

        /**
         * @brief Get the type of the Event
         *
         * @return The Event type
         */
        EVENT_TYPE getEventType() const;

        /**
         * @brief Get the data of the Event
         *
         * @return The data of the Event
         */
        std::shared_ptr<component::Component> getEventData() const;

        private:
        /**
         * @bried The sender of the Event
         */
        EVENT_SENDER _sender;

        /**
         * @brief The type of Event
         */
        EVENT_TYPE _event_type;

        /**
         * @brief The Component concerned by the event
         */
        std::shared_ptr<component::Component> _data;
    };

}

#endif //CPP_RTYPE_2019_EVENT_HPP
