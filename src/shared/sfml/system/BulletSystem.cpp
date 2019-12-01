/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "BulletSystem.hpp"
#include "FireEvent.hpp"

rtype::sfml::system::BulletSystem::BulletSystem(rtype::engine::GameEngine &engine) :
_engine(engine)
{
    _engine.subscribeTo(
        rtype::sfml::event::FireEvent(rtype::sfml::event::FireEvent::FireEventType::ALLY),
        std::bind(&BulletSystem::addBullet, this, std::placeholders::_1)
    );
}

void rtype::sfml::system::BulletSystem::update(float const &delta)
{
    engine::component::ComponentStorage position_store;
    engine::component::ComponentStorage speed_store;
    std::shared_ptr<engine::component::Position> position = nullptr;
    std::shared_ptr<engine::component::Speed> speed = nullptr;
    size_t count = 0;

    position_store = _engine.getComponentStorage<engine::component::Position>();
    speed_store = _engine.getComponentStorage<engine::component::Speed>();
    for (auto &bullet : _bullets) {
        position = position_store.getComponent<engine::component::Position>(bullet->getBulletEntity());
        speed = speed_store.getComponent<engine::component::Speed>(bullet->getBulletEntity());
        if (position && speed) {
            position->x += speed->x;
            if (position->x >= 1920) {
                _engine.destroyEntity(bullet->getBulletEntity());
                _bullets.erase(_bullets.begin() + count);
                return;
            }
        }
        ++count;
    }
}

void rtype::sfml::system::BulletSystem::addEntity(const rtype::engine::entity::Entity &entity)
{
    (void)entity;
}

void rtype::sfml::system::BulletSystem::removeEntity(const rtype::engine::entity::Entity &entity)
{
    (void)entity;
}

void rtype::sfml::system::BulletSystem::addBullet(const rtype::engine::event::Event &event)
{
    auto position = event.getEventData<engine::component::Position>();
    _bullets.emplace_back(std::make_shared<sfml::entity::BulletEntity>(_engine, "./assets/bullet.gif", position->x, position->y, 32, 12, 3, 3, 3, 1));
}
