/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef INPUTEVENT_HPP_
#define INPUTEVENT_HPP_

#include <unordered_map>

#include "Event.hpp"

namespace rtype::sfml::event {

    class InputEvent : public engine::event::Event {

    // @MARK Types
        public:
        enum InputEventType : engine::event::EventType {
            MOUSE_CLICK,
            MOUSE_MOVE,
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

    // @MARK Constructors/Destructors
        public:
        /**
         * @brief Construct a new Input Event
         */
        InputEvent(engine::event::EVENT_SENDER sender, InputEventType event_type, std::shared_ptr<engine::component::Component> data = nullptr);

        /**
         * @brief Destroy the Input Event
         */
        ~InputEvent();

    // @MARK Methods
        private:
        engine::event::EventType getGlobalTypeFromLocal(InputEventType local_type);

    // @MARK Properties
        public:
        static std::unordered_map<InputEventType, engine::event::EventType> map_local_to_global_type;

    };

}

#endif /* !INPUTEVENT_HPP_ */
