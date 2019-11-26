/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "RenderSystem.hpp"
#include "Sprite.hpp"

rtype::sfml::system::RenderSystem::RenderSystem(rtype::engine::GameEngine &engine, sf::RenderWindow &window) :
_engine(engine), _window(window) {}

void rtype::sfml::system::RenderSystem::update(float const &delta)
{
    auto sprite_store = _engine.getComponentStorage<component::Sprite>();
    component::Sprite *sprite = nullptr;

    _window.clear(sf::Color::Black);
    for (auto &entity : _entities) {
        if (sprite_store.entityHasComponent(entity)) {
            sprite = static_cast<component::Sprite *>(_engine.getComponentStorage<component::Sprite>().getComponent(entity).get());
            _window.draw(sprite->sprite);
        }
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
