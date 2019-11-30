/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include "ButtonEntity.hpp"
#include "MouseEntity.hpp"

#include "Collision.hpp"
#include "ButtonSystem.hpp"
#include "RenderSystem.hpp"
#include "CollisionSystem.hpp"
#include "PositionSystem.hpp"
#include "InputEvent.hpp"
#include "CollisionEvent.hpp"

namespace rtype::sfml::entity {

// @xxx WTF can't juste assign it in header file like others !!!
const engine::entity::EntityType ButtonEntity::type = 1 << engine::entity::ENTITY_TYPE::BUTTON;

ButtonEntity::ButtonEntity(engine::GameEngine &game_engine
                          , std::string const &title
                          , float const &x
                          , float const &y
                          , float const &width
                          , float const &height
                          , std::function<void(void)> callback):
    engine::entity::EntityCreator(game_engine),
    _is_hover(false),
    _position(std::make_shared<engine::component::Position>(x, y, true)),
    _button(std::make_shared<sfml::component::Button>(width, height)),
    _text(std::make_shared<sfml::component::Text>(title))
{
    _game_engine.loadComponentStorage<engine::component::Position>();
    _game_engine.loadComponentStorage<engine::component::Collision>();
    _game_engine.loadComponentStorage<component::Text>();
    _game_engine.loadComponentStorage<component::Button>();

    auto button_entity = _game_engine.createEntity();
    auto text_entity = _game_engine.createEntity();

    _game_engine.linkEntityWithComponent(button_entity, engine::component::Position::type, _position);
    _game_engine.linkEntityWithComponent(text_entity, engine::component::Position::type, _position);
    _game_engine.linkEntityWithComponent(button_entity, component::Button::type, _button);
    _game_engine.linkEntityWithComponent(text_entity, component::Text::type, _text);
    _game_engine.linkEntityWithComponent<engine::component::Collision>(button_entity, width, height, type);

    _game_engine.linkEntityWithSystem<system::ButtonSystem>(button_entity);
    _game_engine.linkEntityWithSystem<system::PositionSystem>(button_entity);
    _game_engine.linkEntityWithSystem<system::RenderSystem>(button_entity);
    _game_engine.linkEntityWithSystem<engine::system::CollisionSystem>(button_entity);
    _game_engine.linkEntityWithSystem<system::PositionSystem>(text_entity);
    _game_engine.linkEntityWithSystem<system::RenderSystem>(text_entity);

    _game_engine.subscribeTo(
        engine::event::CollisionEvent(engine::event::CollisionEvent::BEGIN_COLLIDE, button_entity, MouseEntity::type),
        [this] (engine::event::Event const &event) {
            _button->hover = true;
            _text->text.setFillColor(sf::Color::Black);
        }
    );

    _game_engine.subscribeTo(
        engine::event::CollisionEvent(engine::event::CollisionEvent::END_COLLIDE, button_entity, MouseEntity::type),
        [this] (engine::event::Event const &event) {
            _button->hover = false;
            _text->text.setFillColor(sf::Color::White);
        }
    );

    _game_engine.subscribeTo(
        event::InputEvent(event::InputEvent::MOUSE_PRESSED),
        [this] (engine::event::Event const &event) {
            _button->clicked = _button->hover;
        }
    );

    _game_engine.subscribeTo(
        event::InputEvent(event::InputEvent::MOUSE_RELEASED),
        [this] (engine::event::Event const &event) {
            _button->clicked = false;
        }
    );

    _game_engine.subscribeTo(
        event::InputEvent(event::InputEvent::MOUSE_MOVE),
        [this] (engine::event::Event const &event) {
            if (_button->clicked) {
                auto position = event.getEventData<engine::component::Position>();
                _position->x = position->x;
                _position->y = position->y;
            }
        }
    );
}

}
