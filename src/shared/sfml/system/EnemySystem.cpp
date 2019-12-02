/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "EnemySystem.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

rtype::sfml::system::EnemySystem::EnemySystem(rtype::engine::GameEngine &engine) :
_engine(engine)
{
    std::srand(std::time(nullptr));
}

void rtype::sfml::system::EnemySystem::update(float const &delta)
{
    engine::component::ComponentStorage position_store;
    std::shared_ptr<engine::component::Position> position = nullptr;
    static size_t count = 1;

    if (count % 100 != 0) {
        ++count;
        return;
    }
    if (std::rand() % 100 <= 20) {
        spawnEnemy();
    }
    position_store = _engine.getComponentStorage<engine::component::Position>();
    for (auto &enemy : _enemys) {
        position = position_store.getComponent<engine::component::Position>(enemy->getEnemyEntity());
        if (position) {
            switch (std::rand() % 3) {
            case 0: position->y - 10 > 0 ? position->y -= 10 : position->y = position->y; break;
            case 1: position->y + 10 < 1060 ? position->y += 10 : position->y = position->y; break;
            case 2: position->x - 10 < 1885 ? position->x -= 10 : position->x = position->x; break;
            default: break;
            }
        }
    }
    count = 1;
}

void rtype::sfml::system::EnemySystem::addEntity(const rtype::engine::entity::Entity &entity)
{
    (void)entity;
}

void rtype::sfml::system::EnemySystem::removeEntity(const rtype::engine::entity::Entity &entity)
{
    (void)entity;
}

void rtype::sfml::system::EnemySystem::spawnEnemy()
{
    float x = 1885 - std::rand() % 100;
    float y = std::rand() % 1060;
    _enemys.emplace_back(std::make_shared<sfml::entity::EnemyEntity>(_engine, "./assets/enemy.gif", x, y, 33, 17, -3, 3));
}
