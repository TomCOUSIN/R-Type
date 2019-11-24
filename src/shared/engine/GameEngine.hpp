/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_GAMEENGINE_HPP
#define CPP_RTYPE_2019_GAMEENGINE_HPP

#include <vector>
#include <iostream>
#include <unordered_map>
#include "ComponentStorage.hpp"
#include "ISystem.hpp"

using namespace rtype::engine::component;
using namespace rtype::engine::entity;
using namespace rtype::engine::system;

namespace rtype {

    namespace engine {

        /**
         * @brief The GameEngine that handle Entity, System and Component
         */
        class GameEngine {

            public:

            /**
             * @brief Construct a new GameEngine object
             */
            GameEngine();

            /**
             * @brief Destroy a GameEngine object
             */
            ~GameEngine() = default;

            /**
             * @brief Create a new Entity
             *
             * @return The new Entity
             */
            Entity createEntity();

            /**
             * @brief Destroy an Entitys
             *
             * @param entity The Entity to destroy
             */
            void destroyEntity(Entity const &entity);

            /**
             * @brief Load a ComponentStorage to store a specific Component
             *
             * @param type The type of the Component to store
             */
            void loadComponentStorage(ComponentType type);

            /**
             * @brief Load a ComponentStorage to store a specific Component
             *
             * @tparam C The Component to store
             */
            template<typename C>
            void loadComponentStorage() {
                loadComponentStorage(C::type);
            }

            /**
             * @brief Link a Component to an Entity
             *
             * @param entity The Entity to link
             * @param type The type of the Component to link
             * @param component The Component to link
             */
            void linkEntityWithComponent(Entity const &entity, ComponentType type, Component const &component);

            /**
             * @brief Unlink a Component to an Entity
             *
             * @param entity The Entity to unlink
             * @param type The type of the Component to unlink
             */
            void unlinkEntityWithComponent(Entity const &entity, ComponentType type);

            /**
             * @brief Load an ISystem to update Entity's Component values
             *
             * @param system The ISystem to load
             */
            void loadSystem(std::shared_ptr<ISystem> const &system);

            /**
             * @brief Update all Entity's Component values
             *
             * @param delta The deltatime since last update
             */
            void update(float const &delta);

            private:
            /**
             * @brief The counter of the Entity to always have a unique id
             */
            Entity _counter;

            /**
             * @brief The unordered_map of ComponentStorage to store multiple specific Component
             */
            std::unordered_map<ComponentType, ComponentStorage<Component>> _component_store;

            /**
             * @brief The vector of ISystem to update all Entity's Component
             */
            std::vector<std::shared_ptr<ISystem>> _systems;
        };
    }
}

#endif //CPP_RTYPE_2019_GAMEENGINE_HPP
