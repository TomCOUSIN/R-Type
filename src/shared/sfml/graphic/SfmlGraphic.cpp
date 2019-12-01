/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "AnimationSystem.hpp"
#include "ParallaxSystem.hpp"
#include "PositionSystem.hpp"
#include "ButtonSystem.hpp"
#include "RenderSystem.hpp"
#include "InputSystem.hpp"
#include "SfmlGraphic.hpp"
#include "Position.hpp"
#include "Button.hpp"
#include "Sprite.hpp"
#include "Speed.hpp"
#include "Text.hpp"

rtype::sfml::graphic::SfmlGraphic::SfmlGraphic(rtype::engine::GameEngine &engine) :
_mouse(engine), _engine(engine), _window(sf::VideoMode(1920, 1080), "Rtype") {}

void rtype::sfml::graphic::SfmlGraphic::init()
{
    _engine.loadSystem<sfml::system::InputSystem>(_engine, _window);
    _engine.loadSystem<sfml::system::RenderSystem>(_engine, _window);
    _engine.loadSystem<sfml::system::PositionSystem>(_engine);
    _engine.loadSystem<sfml::system::ButtonSystem>(_engine, _window);
    _engine.loadSystem<sfml::system::AnimationSystem>(_engine);
    _engine.loadSystem<sfml::system::ParallaxSystem>(_engine);
    _engine.loadComponentStorage<engine::component::Position>();
    _engine.loadComponentStorage<engine::component::Speed>();
    _engine.loadComponentStorage<sfml::component::Button>();
    _engine.loadComponentStorage<sfml::component::Sprite>();
    _engine.loadComponentStorage<sfml::component::Text>();
}

bool rtype::sfml::graphic::SfmlGraphic::isWindowOpen()
{
    return _window.isOpen();
}

void rtype::sfml::graphic::SfmlGraphic::update(float const &delta)
{
    _engine.update(delta);
}

rtype::engine::entity::Entity rtype::sfml::graphic::SfmlGraphic::createButton(
    std::string const &title
    , float const &x
    , float const &y
    , float const &width
    , float const &height
    , std::function<void(void)> callback)
{
    _buttons.emplace_back(std::make_shared<rtype::sfml::entity::ButtonEntity>(_engine, title, x, y, width, height, callback));
    return _buttons.back()->getButtonEntity();
}

rtype::engine::entity::Entity rtype::sfml::graphic::SfmlGraphic::createText(
    std::string const &message, size_t const &size)
{
    engine::entity::Entity entity = _engine.createEntity();

    _engine.linkEntityWithComponent<sfml::component::Text>(entity, message, size);
    return entity;
}

rtype::engine::entity::Entity rtype::sfml::graphic::SfmlGraphic::createSprite(
    std::string const &texture_path, float const &x, float const &y,
    float const &width, float const &height, float const &scale_width,
    float const &scale_height, size_t const &sprite_count, bool const &movable,
    float const &speed_x, float const &speed_y)
{
    _sprites.emplace_back(std::make_shared<sfml::entity::SpriteEntity>(_engine,
        texture_path, x, y, width, height, scale_width, scale_height, sprite_count, movable, speed_x, speed_y));
    return _sprites.back()->getSpriteEntity();
}

void rtype::sfml::graphic::SfmlGraphic::setPosition(
    const rtype::engine::entity::Entity &entity, float const &x_position,
    float const &y_position)
{
    _engine.linkEntityWithComponent<engine::component::Position>(entity, x_position, y_position, true);
    _engine.linkEntityWithSystem<sfml::system::PositionSystem>(entity);
}

void rtype::sfml::graphic::SfmlGraphic::setVisible(
    const rtype::engine::entity::Entity &entity, bool visible)
{
    if (visible) {
        _engine.linkEntityWithSystem<sfml::system::RenderSystem>(entity);
    } else {
        _engine.unlinkEntityWithSystem<sfml::system::RenderSystem>(entity);
    }
}

void rtype::sfml::graphic::SfmlGraphic::removeElement(const rtype::engine::entity::Entity &entity)
{
    for (auto &button : _buttons) {
        if (button->getButtonEntity() == entity) {
            button->destroyEntityButton();
            return;
        }
    }
    for (auto &parallax : _parallax) {
        if (parallax->getBackgroundEntity() == entity) {
            parallax->destroyParallax();
            return;
        }
    }
    _engine.destroyEntity(entity);
}

bool rtype::sfml::graphic::SfmlGraphic::isButtonClicked(const rtype::engine::entity::Entity &entity)
{
    auto store = _engine.getComponentStorage<component::Button>();
    std::shared_ptr<component::Button> button = nullptr;

    if (store.entityHasComponent(entity)) {
        button = store.getComponent<component::Button>(entity);
        return button->clicked;
    }
    return false;
}

rtype::engine::entity::Entity rtype::sfml::graphic::SfmlGraphic::createParallax(
    std::string const &background_path, std::string const &foreground_path,
    float const &background_speed_x)
{
    _parallax.emplace_back(std::make_shared<sfml::entity::ParallaxEntity>(_engine, background_path, foreground_path, background_speed_x));
    return _parallax.back()->getBackgroundEntity();
}

