/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include "InputEvent.hpp"

namespace rtype::sfml::event {

InputEvent::InputEvent(InputEventType event_type, std::shared_ptr<engine::component::Component> data) :
    Event(engine::event::EVENT_SENDER::INPUT, event_type, data)
{
}

InputEvent::~InputEvent()
{
}

}
