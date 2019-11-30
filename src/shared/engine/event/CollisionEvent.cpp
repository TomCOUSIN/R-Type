/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include "CollisionEvent.hpp"

namespace rtype::engine::event {

CollisionEvent::CollisionEvent(CollisionEventType event_type, engine::entity::Entity entity, component::Collision::IdType component_type) :
    Event(engine::event::EVENT_SENDER::COLLISION, (component_type ^ entity) << event_type)
{
}

CollisionEvent::CollisionEvent(CollisionEventType event_type, component::Collision::IdType id) :
    Event(engine::event::EVENT_SENDER::COLLISION, id << event_type)
{
}

}
