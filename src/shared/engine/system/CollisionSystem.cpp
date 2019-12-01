/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by lucasmrdt
*/

#include "CollisionSystem.hpp"
#include "CollisionEvent.hpp"

// @todo optimize this !

namespace rtype::engine::system {

CollisionSystem::CollisionSystem(GameEngine &engine) :
_engine(engine) {
}

void CollisionSystem::update(float const &delta)
{
    static engine::component::ComponentStorage position_store;
    if (position_store.size() == 0) {
        position_store = _engine.getComponentStorage<component::Position>();
    }

    static engine::component::ComponentStorage collision_store;
    if (collision_store.size() == 0) {
        collision_store = _engine.getComponentStorage<component::Collision>();
    }

    for (size_t i = 0; i < _entities.size(); ++i) {
        for (size_t j = i + 1; j < _entities.size(); ++j) {
            auto &entity_a = _entities[i];
            auto &entity_b = _entities[j];
            if (collision_store.entityHasComponent(entity_a) && position_store.entityHasComponent(entity_a)
            && collision_store.entityHasComponent(entity_b) && position_store.entityHasComponent(entity_b)) {
                auto collision_a = collision_store.getComponent<component::Collision>(entity_a);
                auto position_a = position_store.getComponent<component::Position>(entity_a);
                auto collision_b = collision_store.getComponent<component::Collision>(entity_b);
                auto position_b = position_store.getComponent<component::Position>(entity_b);
                checkCollision(entity_a, entity_b, collision_a, position_a, collision_b, position_b);
            }
        }
    }
    for (auto &collision_id : _previous_collisions) {
        _engine.dispatchEvent(event::CollisionEvent(event::CollisionEvent::END_COLLIDE, collision_id));
    }
    _previous_collisions = _current_collisions;
    _current_collisions.clear();
}

void CollisionSystem::addEntity(const entity::Entity &entity)
{
    _entities.push_back(entity);
}

void CollisionSystem::removeEntity(const entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}

void CollisionSystem::checkCollision(engine::entity::Entity const &entity_a
                                    , engine::entity::Entity const &entity_b
                                    , std::shared_ptr<component::Collision> collision_a
                                    , std::shared_ptr<component::Position> position_a
                                    , std::shared_ptr<component::Collision> collision_b
                                    , std::shared_ptr<component::Position> position_b)
{
    auto rect_a = getRect(collision_a, position_a);
    auto rect_b = getRect(collision_b, position_b);

    // @todo no check when the first can contains the second
    if (rect_a.right < rect_b.left
    || rect_a.left > rect_b.right
    || rect_a.bottom < rect_b.top
    || rect_a.top > rect_b.bottom) {
        return;
    }
    _engine.dispatchEvent(event::CollisionEvent(event::CollisionEvent::BEGIN_COLLIDE, entity_a, collision_b->id));
    _engine.dispatchEvent(event::CollisionEvent(event::CollisionEvent::BEGIN_COLLIDE, entity_b, collision_a->id));
    auto id_a = event::CollisionEvent::getId(entity_a, collision_b->id);
    auto id_b = event::CollisionEvent::getId(entity_b, collision_a->id);
    _previous_collisions.erase(id_a);
    _previous_collisions.erase(id_b);
    _current_collisions.insert(id_a);
    _current_collisions.insert(id_b);
}

CollisionSystem::Rect CollisionSystem::getRect(std::shared_ptr<component::Collision> collision
                                              , std::shared_ptr<component::Position> position) const
{
    Rect rect;

    rect.left = position->is_centered ? position->x - collision->width/2 : position->x;
    rect.right = position->is_centered ? position->x + collision->width/2 : position->x + collision->width;
    rect.top = position->is_centered ? position->y - collision->height/2 : position->y;
    rect.bottom = position->is_centered ? position->y + collision->height/2 : position->y + collision->height;
    return rect;
}

}
