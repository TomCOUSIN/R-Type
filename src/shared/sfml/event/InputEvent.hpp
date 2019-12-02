/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef INPUTEVENT_HPP_
#define INPUTEVENT_HPP_

#include <unordered_map>

#include "Game.hpp"
#include "Event.hpp"

namespace rtype::sfml::event {

    class InputEvent : public engine::event::Event {

    // @MARK Types
        public:
        enum InputEventType : engine::event::EventType {
            ARROW_UP = game::event::ARROW_UP,
            ARROW_DOWN = game::event::ARROW_DOWN,
            ARROW_RIGHT = game::event::ARROW_RIGHT,
            ARROW_LEFT = game::event::ARROW_LEFT,
            MOUSE_PRESSED = game::event::LastInputEventType,
            MOUSE_RELEASED,
            MOUSE_MOVED,
            BACKSPACE,
            TEXT_ENTERED,
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

        static const size_t VISIBLE_UTF_CODE = 32;

    // @MARK Constructors/Destructors
        public:
        /**
         * @brief Construct a new Input Event
         */
        InputEvent(InputEventType event_type, std::shared_ptr<engine::component::Component> data = nullptr);

        /**
         * @brief Destroy the Input Event
         */
        ~InputEvent();

    };

}

#endif /* !INPUTEVENT_HPP_ */
