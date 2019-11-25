/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "RenderSystem.hpp"
#include "Sprite.hpp"

RenderSystem::RenderSystem(rtype::engine::GameEngine &engine, sf::RenderWindow &window) :
    _engine(engine), _window(window) {}

void rtype::engine::system::RenderSystem::update(float const &delta)
{
    _window.clear(sf::Color::Black);
    for (Entity entity = 0; entity < _engine.getEntityCounter(); ++entity) {
        if (_engine.getComponentStorage<Sprite>().entityHasComponent(entity)) {
            Sprite *sprite = static_cast<Sprite *>(_engine.getComponentStorage<Sprite>().getComponent(entity).get());
            _window.draw(sprite->sprite);
        }
    }
    _window.display();
}
