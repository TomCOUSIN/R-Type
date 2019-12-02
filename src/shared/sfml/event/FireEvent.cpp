/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "FireEvent.hpp"

rtype::sfml::event::FireEvent::FireEvent(
    rtype::sfml::event::FireEvent::FireEventType event_type) :
rtype::engine::event::Event(engine::event::EVENT_SENDER::ENTITY, event_type)
{}

rtype::sfml::event::FireEvent::FireEvent(
    rtype::sfml::event::FireEvent::FireEventType event_type
    , std::shared_ptr<engine::component::Position> position) :
rtype::engine::event::Event(engine::event::EVENT_SENDER::ENTITY, event_type, position)
{}
