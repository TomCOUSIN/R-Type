/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_IEVENT_HPP
#define CPP_RTYPE_2019_IEVENT_HPP

namespace rtype::engine::event {

    /**
     * @brief Enum to define Event sender
     */
    enum EVENT_SENDER {
        MOUSE,
        KEYBOARD
    };

    /**
     * @brief Enum to define Event type
     */
    enum EVENT_TYPE {
        MOUSE_CLICK,
        ARROW_UP,
        ARROW_DOWN,
        ARROW_RIGHT,
        ARROW_LEFT,
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,
        SPACE,
        ENTER,
        ESCAPE
    };

    /**
     * @brief Interface IEvent to handle all GameEngine event
     */
    class IEvent {

        public:
        /**
         * @brief Destroy an IEvent object
         */
        virtual ~IEvent() = default;
    };
}

#endif //CPP_RTYPE_2019_IEVENT_HPP
