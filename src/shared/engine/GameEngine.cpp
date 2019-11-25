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
    _component_store.emplace(std::make_pair(type, ComponentStorage<std::shared_ptr<Component>>()));
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

ComponentStorage<std::shared_ptr<Component>> GameEngine::getComponentStorage(ComponentType type) const
{
    auto component_storage = _component_store.find(type);
    return component_storage->second;
}

unsigned long GameEngine::getEntityCounter() const
{ return _counter; }

void GameEngine::linkEntityWithComponent(Entity const &entity, ComponentType type, std::shared_ptr<Component> ptr)
{
    auto component_storage = _component_store.find(type);
    if (component_storage != _component_store.end()) {
        component_storage->second.addEntity(entity, ptr);
    }
}
