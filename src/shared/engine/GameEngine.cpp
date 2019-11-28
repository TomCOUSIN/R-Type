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

entity::Entity GameEngine::createEntity()
{ return _counter++; }

void GameEngine::destroyEntity(entity::Entity const &entity)
{
    for (auto &component_storage: _component_store) {
        component_storage.second.removeEntity(entity);
    }
}

void GameEngine::loadComponentStorage(component::ComponentType type)
{
    _component_store.emplace(std::make_pair(type, component::ComponentStorage<std::shared_ptr<component::Component>>()));
}

void GameEngine::linkEntityWithComponent(entity::Entity const &entity, component::ComponentType type, std::shared_ptr<component::Component> ptr)
{
    auto component_storage = _component_store.find(type);
    if (component_storage != _component_store.end()) {
        component_storage->second.addEntity(entity, ptr);
    }
}

void GameEngine::unlinkEntityWithComponent(entity::Entity const &entity, component::ComponentType type)
{
    auto component_storage = _component_store.find(type);
    if (component_storage != _component_store.end()) {
        component_storage->second.removeEntity(entity);
    }
}

void GameEngine::loadSystem(system::SystemType type, std::shared_ptr<system::ISystem> const &system)
{
    _systems.emplace(std::make_pair(type, system));
}

void GameEngine::update(float const &delta)
{
    for (const auto& system : _systems) {
        system.second->update(delta);
    }
    _events.clear();
}

component::ComponentStorage<std::shared_ptr<component::Component>> GameEngine::getComponentStorage(component::ComponentType type) const
{
    auto component_storage = _component_store.find(type);
    return component_storage->second;
}

void GameEngine::linkEntityWithSystem(entity::Entity const &entity, system::SystemType type)
{
    auto system = _systems.find(type);
    if (system != _systems.end()) {
        system->second->addEntity(entity);
    }
}

void GameEngine::addEvent(event::Event const &event)
{ _events.push_back(event); }

std::vector<event::Event> GameEngine::getEvent() const
{ return _events; }
