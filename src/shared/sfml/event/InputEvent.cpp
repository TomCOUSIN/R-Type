/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include "InputEvent.hpp"

namespace rtype::sfml::event {

std::unordered_map<InputEvent::InputEventType, engine::event::EventType> InputEvent::map_local_to_global_type;

InputEvent::InputEvent(engine::event::EVENT_SENDER sender, InputEventType event_type, std::shared_ptr<engine::component::Component> data) :
    Event(sender, getGlobalTypeFromLocal(event_type), data)
{
}

InputEvent::~InputEvent()
{
}

engine::event::EventType
InputEvent::getGlobalTypeFromLocal(InputEventType local_type)
{
    auto global_type = map_local_to_global_type.find(local_type);

    if (global_type != map_local_to_global_type.end()) {
        return global_type->second;
    }
    auto new_global_type = Event::event_type_counter++;
    map_local_to_global_type.emplace(std::make_pair(local_type, new_global_type));
    return new_global_type;
}

}
