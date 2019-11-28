/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "Event.hpp"

rtype::engine::event::Event::Event(rtype::engine::event::EVENT_SENDER sender,
    rtype::engine::event::EVENT_TYPE event_type,
    std::shared_ptr<component::Component> data) :
    _sender(sender), _event_type(event_type), _data(data) {}

rtype::engine::event::EVENT_SENDER rtype::engine::event::Event::getSender() const
{ return _sender; }

rtype::engine::event::EVENT_TYPE rtype::engine::event::Event::getEventType() const
{ return _event_type;}

std::shared_ptr<rtype::engine::component::Component> rtype::engine::event::Event::getEventData() const
{ return _data; }
