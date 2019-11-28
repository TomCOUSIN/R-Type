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
        renderSprite(entity);
        renderButton(entity);
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
    auto sprite_store = _engine.getComponentStorage<component::Sprite>();
    component::Sprite *sprite = nullptr;

    if (sprite_store.entityHasComponent(entity)) {
        sprite = static_cast<component::Sprite *>(sprite_store.getComponent(entity).get());
        _window.draw(sprite->sprite);
    }
}

void rtype::sfml::system::RenderSystem::renderButton(const engine::entity::Entity &entity)
{
    auto button_store = _engine.getComponentStorage<component::Button>();
    component::Button *button = nullptr;

    if (button_store.entityHasComponent(entity)) {
        button = static_cast<component::Button *>(button_store.getComponent(entity).get());
        _window.draw(button->shape);
    }
}

void rtype::sfml::system::RenderSystem::renderText(const engine::entity::Entity &entity)
{
    auto text_store = _engine.getComponentStorage<component::Text>();
    component::Text *text = nullptr;

    if (text_store.entityHasComponent(entity)) {
        text = static_cast<component::Text *>(text_store.getComponent(entity).get());
        _window.draw(text->text);
    }
}
