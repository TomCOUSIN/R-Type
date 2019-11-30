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

    // @MARK Constructors/Destructors
        public:
        /**
         * @brief Construct an Event object
         */
        Event(EVENT_SENDER sender, EventType event_type, std::shared_ptr<component::Component> data = nullptr);

        /**
         * @brief Construct an Event object
         */
        Event(EVENT_SENDER sender, std::shared_ptr<component::Component> data = nullptr);


        /**
         * @brief Destroy an Event object
         */
        ~Event() override = default;

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
        EventType getEventType() const;

        /**
         * @brief Get the data of the Event
         *
         * @return The data of the Event
         */
        std::shared_ptr<component::Component> getEventData() const;

        template <typename C>
        std::shared_ptr<C> getEventData() const
        {
            static_assert(std::is_base_of<component::Component, C>::value, "You need to pass a Component");
            return std::dynamic_pointer_cast<C>(_data);
        }

    // @MARK Properties
        public:
        static EventType event_type_counter;

        protected:
        /**
         * @bried The sender of the Event
         */
        EVENT_SENDER _sender;

        /**
         * @brief The type of Event
         */
        EventType _event_type;

        /**
         * @brief The Component concerned by the event
         */
        std::shared_ptr<component::Component> _data;
    };

    // @MARK Types
        using EventCallback = std::function<void(Event const &)>;

}

#endif //CPP_RTYPE_2019_EVENT_HPP
