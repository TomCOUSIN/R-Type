/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include "ButtonEntity.hpp"

#include "Button.hpp"
#include "Text.hpp"
#include "ButtonSystem.hpp"
#include "RenderSystem.hpp"
#include "PositionSystem.hpp"
#include "InputEvent.hpp"

namespace rtype::sfml::entity {

ButtonEntity::ButtonEntity(engine::GameEngine &game_engine
                          , std::string const &title
                          , float const &x
                          , float const &y
                          , float const &width
                          , float const &height
                          , std::function<void(void)> callback):
    engine::entity::EntityCreator(game_engine),
    _position(std::make_shared<engine::component::Position>(x, y))
{
    _game_engine.loadComponentStorage<engine::component::Position>();
    _game_engine.loadComponentStorage<component::Text>();
    _game_engine.loadComponentStorage<component::Button>();

    auto button_entity = _game_engine.createEntity();
    auto text_entity = _game_engine.createEntity();

    _game_engine.linkEntityWithComponent(button_entity, engine::component::Position::type, _position);
    _game_engine.linkEntityWithComponent(text_entity, engine::component::Position::type, _position);
    _game_engine.linkEntityWithComponent<component::Button>(button_entity, width, height);
    _game_engine.linkEntityWithComponent<component::Text>(text_entity, title);

    _game_engine.linkEntityWithSystem<system::PositionSystem>(button_entity);
    _game_engine.linkEntityWithSystem<system::PositionSystem>(text_entity);
    _game_engine.linkEntityWithSystem<system::RenderSystem>(button_entity);
    _game_engine.linkEntityWithSystem<system::RenderSystem>(text_entity);

    _game_engine.subscribeTo(
        event::InputEvent(engine::event::EVENT_SENDER::MOUSE, event::InputEvent::MOUSE_CLICK),
        [this] (engine::event::Event const &event) {
            auto data = event.getEventData<engine::component::Position>();
            std::cout << "clicked: " << data->x << ":" << data->y << std::endl;
            _position->x = data->x;
            _position->y = data->y;
        }
    );
}

}
