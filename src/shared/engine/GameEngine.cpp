/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "GameEngine.hpp"

using namespace rtype::engine;

GameEngine::GameEngine() :
_counter(0) {}

Entity GameEngine::createEntity()
{ return _counter++; }

void GameEngine::destroyEntity(Entity const &entity)
{
    for (auto &component_storage: _component_store) {
        component_storage.second.removeEntity(entity);
    }
}

void GameEngine::loadComponentStorage(ComponentType type)
{
    _component_store.emplace(std::make_pair(type, ComponentStorage<Component>()));
}

void GameEngine::linkEntityWithComponent(Entity const &entity, ComponentType type, Component const &component)
{
    auto component_storage = _component_store.find(type);
    if (component_storage != _component_store.end()) {
        component_storage->second.addEntity(entity, component);
    }
}

void GameEngine::unlinkEntityWithComponent(Entity const &entity, ComponentType type)
{
    auto component_storage = _component_store.find(type);
    if (component_storage != _component_store.end()) {
        component_storage->second.removeEntity(entity);
    }
}

void GameEngine::loadSystem(std::shared_ptr<ISystem> const &system)
{
    _systems.push_back(system);
}

void GameEngine::update(float const &delta)
{
    for (auto &system : _systems) {
        system->update(delta);
    }
}
