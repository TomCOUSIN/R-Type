/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "GameEngine.hpp"

/**
 * @brief Construct a new GameEngine object
 */
rtype::engine::GameEngine::GameEngine() :
_entity_manager(),
_positions(),
_directions(),
_speeds(),
_systems(),
_entitys()
{
    _systems.emplace_back(new system::MovementSystem(_positions, _directions, _speeds));
}

/**
 * @brief Update all the Entity's component of the GameEngine using Systems
 */
void rtype::engine::GameEngine::update()
{
    for (auto &system : _systems) {
        system->update();
    }
}

/**
 * @brief Create an Entity and associate it with a name
 *
 * @param entity_name The name of the entity to create
 */
void rtype::engine::GameEngine::createEntity(std::string const &entity_name)
{
    _entitys.emplace(std::pair< std::string, unsigned long>(entity_name, _entity_manager.createNewEntity().getUniqueId()));
}

/**
 * @brief Destroy an Entity from the GameEngine
 * @param entity_name The name of the Entity to destroy
 */
void rtype::engine::GameEngine::destroyEntity(std::string const &entity_name)
{
    // TODO Loop in the ComponentManager vector
    _entity_manager.removeEntity(_entitys[entity_name]);
    _positions.removeComponentByEntity(_entitys[entity_name]);
    _directions.removeComponentByEntity(_entitys[entity_name]);
    _speeds.removeComponentByEntity(_entitys[entity_name]);
    _entitys.erase(_entitys.find(entity_name));
}

/**
 * @brief Get the list of all Entity object with associated name stored in GameEngine

 * @return The list of Entity with their name
 */
std::unordered_map<std::string, unsigned long> rtype::engine::GameEngine::getEntitys() const
{ return _entitys; }
