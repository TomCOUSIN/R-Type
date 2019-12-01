/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "RenderSystem.hpp"
#include "Sprite.hpp"
#include "Button.hpp"
#include "Text.hpp"

rtype::sfml::system::RenderSystem::RenderSystem(rtype::engine::GameEngine &engine, sf::RenderWindow &window) :
_engine(engine), _window(window) {}

void rtype::sfml::system::RenderSystem::update(float const &delta)
{
    _window.clear(sf::Color::Black);
    for (auto &entity : _entities) {
        if (_engine.hasComponentStorage<component::Sprite>())
            renderSprite(entity);
        if (_engine.hasComponentStorage<component::Button>())
            renderButton(entity);
        if (_engine.hasComponentStorage<component::Text>())
            renderText(entity);
    }
    _window.display();
}

void rtype::sfml::system::RenderSystem::addEntity(const engine::entity::Entity &entity)
{
    _entities.push_back(entity);
}

void rtype::sfml::system::RenderSystem::removeEntity(const engine::entity::Entity &entity)
{
    for (unsigned long index = 0; index < _entities.size(); ++index) {
        if (_entities[index] == entity) {
            _entities.erase(_entities.begin() + index);
            break;
        }
        ++index;
    }
}

void rtype::sfml::system::RenderSystem::renderSprite(const engine::entity::Entity &entity)
{
    static engine::component::ComponentStorage sprite_store;
    if (sprite_store.size() == 0) {
        sprite_store = _engine.getComponentStorage<component::Sprite>();
    }

    if (sprite_store.entityHasComponent(entity)) {
        auto sprite = sprite_store.getComponent<component::Sprite>(entity);
        _window.draw(sprite->sprite);
    }
}

void rtype::sfml::system::RenderSystem::renderButton(const engine::entity::Entity &entity)
{
    static engine::component::ComponentStorage button_store;
    if (button_store.size() == 0) {
        button_store = _engine.getComponentStorage<component::Button>();
    }

    if (button_store.entityHasComponent(entity)) {
        auto button = button_store.getComponent<component::Button>(entity);
        _window.draw(button->shape);
    }
}

void rtype::sfml::system::RenderSystem::renderText(const engine::entity::Entity &entity)
{
    static engine::component::ComponentStorage text_store;
    if (text_store.size() == 0) {
        text_store = _engine.getComponentStorage<component::Text>();
    }

    if (text_store.entityHasComponent(entity)) {
        auto text = text_store.getComponent<component::Text>(entity);
        _window.draw(text->text);
    }
}
