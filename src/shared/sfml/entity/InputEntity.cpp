/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include "InputEntity.hpp"
#include "MouseEntity.hpp"

#include "Collision.hpp"
#include "Key.hpp"
#include "InputSystem.hpp"
#include "ButtonSystem.hpp"
#include "RenderSystem.hpp"
#include "CollisionSystem.hpp"
#include "PositionSystem.hpp"
#include "InputEvent.hpp"
#include "CollisionEvent.hpp"

namespace rtype::sfml::entity {

    const engine::entity::EntityType InputEntity::type = 1 << engine::entity::ENTITY_TYPE::INPUT;

    InputEntity::InputEntity(engine::GameEngine &game_engine
                            , std::string const &title
                            , float const &x
                            , float const &y
                            , float const &width
                            , float const &height
                            , std::function<void(std::string)> on_submit
						    , std::size_t max_chars):
        engine::entity::EntityCreator(game_engine),
        _value(),
        _on_submit(on_submit),
        _max_chars(max_chars),
        _position(std::make_shared<engine::component::Position>(x, y)),
        _input(std::make_shared<sfml::component::Button>(width, height)),
        _text(std::make_shared<sfml::component::Text>("", 24))
    {
        _game_engine.loadComponentStorage<engine::component::Position>();
        _game_engine.loadComponentStorage<engine::component::Collision>();
        _game_engine.loadComponentStorage<component::Text>();
        _game_engine.loadComponentStorage<component::Button>();

        auto input_entity = _game_engine.createEntity();
        auto value_entity = _game_engine.createEntity();
        auto title_entity = _game_engine.createEntity();
        _input_entity = input_entity;
        _value_entity = value_entity;
        _title_entity = title_entity;

        _game_engine.linkEntityWithComponent(input_entity, component::Button::type, _input);
        _game_engine.linkEntityWithComponent(input_entity, engine::component::Position::type, _position);
        _game_engine.linkEntityWithComponent<engine::component::Collision>(input_entity, width, height, InputEntity::type);
        _game_engine.linkEntityWithComponent<engine::component::Position>(title_entity, x - width * 1.2, y);
        _game_engine.linkEntityWithComponent<component::Text>(title_entity, title, 24);
        _game_engine.linkEntityWithComponent(value_entity, component::Text::type, _text);
        _game_engine.linkEntityWithComponent(value_entity, engine::component::Position::type, _position);

        _game_engine.linkEntityWithSystem<system::PositionSystem>(input_entity);
        _game_engine.linkEntityWithSystem<system::RenderSystem>(input_entity);
        _game_engine.linkEntityWithSystem<engine::system::CollisionSystem>(input_entity);
        _game_engine.linkEntityWithSystem<system::PositionSystem>(title_entity);
        _game_engine.linkEntityWithSystem<system::RenderSystem>(title_entity);
        _game_engine.linkEntityWithSystem<system::PositionSystem>(value_entity);
        _game_engine.linkEntityWithSystem<system::RenderSystem>(value_entity);

        _game_engine.subscribeTo(
            engine::event::CollisionEvent(engine::event::CollisionEvent::BEGIN_COLLIDE, input_entity, MouseEntity::type),
            std::bind(&InputEntity::onMouseCollide, this, std::placeholders::_1)
        );
        _game_engine.subscribeTo(
            engine::event::CollisionEvent(engine::event::CollisionEvent::END_COLLIDE, input_entity, MouseEntity::type),
            std::bind(&InputEntity::onMouseEndCollide, this, std::placeholders::_1)
        );
        _game_engine.subscribeTo(
            event::InputEvent(event::InputEvent::MOUSE_PRESSED),
            std::bind(&InputEntity::onMousePressed, this, std::placeholders::_1)
        );
        _game_engine.subscribeTo(
            event::InputEvent(event::InputEvent::TEXT_ENTERED),
            std::bind(&InputEntity::onTextEntered, this, std::placeholders::_1)
        );
        _game_engine.subscribeTo(
            event::InputEvent(event::InputEvent::BACKSPACE),
            std::bind(&InputEntity::onBackspace, this, std::placeholders::_1)
        );
        _game_engine.subscribeTo(
            event::InputEvent(event::InputEvent::ENTER),
            std::bind(&InputEntity::onSubmit, this, std::placeholders::_1)
        );
    }

    void InputEntity::onMousePressed(engine::event::Event const &event)
    {
        _input->clicked = _input->hover;
        if (_input->clicked) {
            _input->shape.setFillColor(sf::Color::White);
            _text->text.setFillColor(sf::Color::Black);
        } else {
            _on_submit(_value);
            _input->shape.setFillColor(sf::Color::Black);
            _text->text.setFillColor(sf::Color::White);
        }
    }

    void InputEntity::onMouseCollide(engine::event::Event const &event)
    {
        _input->hover = true;
        _input->shape.setFillColor(sf::Color::White);
        _text->text.setFillColor(sf::Color::Black);
    }

    void InputEntity::onMouseEndCollide(engine::event::Event const &event)
    {
        _input->hover = false;
        if (!_input->clicked) {
            _input->shape.setFillColor(sf::Color::Black);
            _text->text.setFillColor(sf::Color::White);
        }
    }

    void InputEntity::onTextEntered(engine::event::Event const &event)
    {
        if (_input->clicked && _value.size() < _max_chars) {
            auto data = event.getEventData<engine::component::Key>();
            _value += data->value;
            _text->update(_value);
        }
    }

    void InputEntity::onBackspace(engine::event::Event const &event)
    {
        if (_input->clicked && _value.size() > 0) {
            _value = _value.substr(0, _value.size() - 1);
            _text->update(_value);
        }
    }

    void InputEntity::onSubmit(engine::event::Event const &event)
    {
        if (_input->clicked) {
            _on_submit(_value);
        }
    }

    engine::entity::Entity InputEntity::getInputEntity() const
    {
        return _input_entity;
    }

    void InputEntity::destroyEntityInput()
    {
        _game_engine.destroyEntity(_input_entity);
        _game_engine.destroyEntity(_value_entity);
        _game_engine.destroyEntity(_title_entity);
    }
}
