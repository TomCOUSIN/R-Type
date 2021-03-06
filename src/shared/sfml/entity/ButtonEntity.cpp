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
        _callback(callback),
        _position(std::make_shared<engine::component::Position>(x, y)),
        _button(std::make_shared<sfml::component::Button>(width, height)),
        _text(std::make_shared<sfml::component::Text>(title, 24))
    {
        _game_engine.loadComponentStorage<engine::component::Position>();
        _game_engine.loadComponentStorage<engine::component::Collision>();
        _game_engine.loadComponentStorage<component::Text>();
        _game_engine.loadComponentStorage<component::Button>();

        auto button_entity = _game_engine.createEntity();
        auto text_entity = _game_engine.createEntity();
        _button_entity = button_entity;
        _text_entity = text_entity;

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
            std::bind(&ButtonEntity::onMouseCollide, this, std::placeholders::_1)
        );
        _game_engine.subscribeTo(
            engine::event::CollisionEvent(engine::event::CollisionEvent::END_COLLIDE, button_entity, MouseEntity::type),
            std::bind(&ButtonEntity::onMouseEndCollide, this, std::placeholders::_1)
        );
        _game_engine.subscribeTo(
            event::InputEvent(event::InputEvent::MOUSE_PRESSED),
            std::bind(&ButtonEntity::onMousePressed, this, std::placeholders::_1)
        );
        _game_engine.subscribeTo(
            event::InputEvent(event::InputEvent::MOUSE_RELEASED),
            std::bind(&ButtonEntity::onMouseReleased, this, std::placeholders::_1)
        );
    }

    void ButtonEntity::onMousePressed(engine::event::Event const &event)
    {
        _button->clicked = _button->hover;
        if (_button->clicked) {
            _button->shape.setFillColor(sf::Color::Red);
        }
    }

    void ButtonEntity::onMouseReleased(engine::event::Event const &event)
    {
        if (_button->clicked) {
            _callback();
        }
        _button->clicked = false;
    }

    void ButtonEntity::onMouseCollide(engine::event::Event const &event)
    {
        _button->hover = true;
        _text->text.setFillColor(sf::Color::Black);
    }

    void ButtonEntity::onMouseEndCollide(engine::event::Event const &event)
    {
        _button->hover = false;
        _text->text.setFillColor(sf::Color::White);
    }

    engine::entity::Entity ButtonEntity::getButtonEntity() const
    {
        return _button_entity;
    }

    void ButtonEntity::destroyEntityButton()
    {
        _game_engine.destroyEntity(_button_entity);
        _game_engine.destroyEntity(_text_entity);
    }
}
