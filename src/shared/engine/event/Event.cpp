/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "Event.hpp"

namespace rtype::engine::event {

Event::Event(EVENT_SENDER sender,
    EventType event_type,
    std::shared_ptr<component::Component> data) :
    _sender(sender), _event_type(event_type), _data(data) {}

Event::Event(EVENT_SENDER sender,
    std::shared_ptr<component::Component> data) :
    _sender(sender), _event_type(NONE_TYPE), _data(data) {}

EVENT_SENDER Event::getSender() const
{ return _sender; }

EventType Event::getEventType() const
{ return _event_type;}

std::shared_ptr<rtype::engine::component::Component> Event::getEventData() const
{ return _data; }

}

