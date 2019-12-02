/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_IEVENT_HPP
#define CPP_RTYPE_2019_IEVENT_HPP

#include <functional>

#include "Entity.hpp"

namespace rtype::engine::event {

    /**
     * @brief Enum to define Event sender
     */
    enum EVENT_SENDER {
        INPUT,
        COLLISION,
        NETWORK,
        ENTITY,
        FIRE
    };

    /**
     * @brief Type to define Event type
     */
    using EventType = std::uint32_t;

    #define NONE_TYPE (-1)

    /**
     * @brief Interface IEvent to handle all GameEngine event
     */
    class IEvent {

    // @MARK Constructors/Destructors
        public:
        /**
         * @brief Destroy an IEvent object
         */
        virtual ~IEvent() = default;

    };

}

#endif //CPP_RTYPE_2019_IEVENT_HPP
