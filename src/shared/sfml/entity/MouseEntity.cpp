/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include "MouseEntity.hpp"

#include "Collision.hpp"
#include "PositionSystem.hpp"
#include "CollisionSystem.hpp"
#include "InputEvent.hpp"

namespace rtype::sfml::entity {

// @xxx WTF can't juste assign it in header file like others !!!
const engine::entity::EntityType MouseEntity::type = 1 << engine::entity::ENTITY_TYPE::MOUSE;

MouseEntity::MouseEntity(engine::GameEngine &game_engine):
    engine::entity::EntityCreator(game_engine),
    _clicked(true),
    _position(std::make_shared<engine::component::Position>(0, 0))
{
    _game_engine.loadSystem<system::PositionSystem>(_game_engine);
    _game_engine.loadSystem<engine::system::CollisionSystem>(_game_engine);

    _game_engine.loadComponentStorage<engine::component::Position>();
    _game_engine.loadComponentStorage<engine::component::Collision>();

    auto mouse_entity = _game_engine.createEntity();
    _game_engine.linkEntityWithComponent(mouse_entity, engine::component::Position::type, _position);
    _game_engine.linkEntityWithComponent<engine::component::Collision>(mouse_entity, 1, 1, type);

    _game_engine.linkEntityWithSystem<system::PositionSystem>(mouse_entity);
    _game_engine.linkEntityWithSystem<engine::system::CollisionSystem>(mouse_entity);

    _game_engine.subscribeTo(
        event::InputEvent(event::InputEvent::MOUSE_MOVED),
        std::bind(&MouseEntity::onMouseMove, this, std::placeholders::_1)
    );
}

void
MouseEntity::onMouseMove(engine::event::Event const &event)
{
    auto data = event.getEventData<engine::component::Position>();
    _position->x = data->x;
    _position->y = data->y;
}

}
