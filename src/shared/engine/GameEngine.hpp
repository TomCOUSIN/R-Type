/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_GAMEENGINE_HPP
#define CPP_RTYPE_2019_GAMEENGINE_HPP

#include <map>
#include <vector>
#include <iostream>
#include <functional>

#include "ComponentStorage.hpp"
#include "ISystem.hpp"
#include "Event.hpp"

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
             * @brief Get A ComponentStorage according to the ComponentType
             *
             * @param type The type of the Component stored in the ComponentStorage
             * @return The ComponentStorage
             */
            component::ComponentStorage<component::Component> getComponentStorage(component::ComponentType type) const;

            /**
             * @brief Get A ComponentStorage according to the Component
             *
             * @tparam C The Component stored in the ComponentStorage
             * @return The ComponentStorage
             */
            template<typename C>
            component::ComponentStorage<component::Component> getComponentStorage() const {
                static_assert(std::is_base_of<component::Component, C>::value, "You need to pass a Component");
                return getComponentStorage(C::type);
            }

            /**
             * @brief Create a new Entity
             *
             * @return The new Entity
             */
            entity::Entity createEntity();

            /**
             * @brief Destroy an Entitys
             *
             * @param entity The Entity to destroy
             */
            void destroyEntity(entity::Entity const &entity);

            /**
             * @brief Load a ComponentStorage to store a specific Component
             *
             * @param type The type of the Component to store
             */
            void loadComponentStorage(component::ComponentType type);

            /**
             * @brief Load a ComponentStorage to store a specific Component
             *
             * @tparam C The Component to store
             */
            template<typename C>
            void loadComponentStorage() {
                static_assert(std::is_base_of<component::Component, C>::value, "You need to pass a Component");
                loadComponentStorage(C::type);
            }

            /**
             * @brief Link a Component to an Entity
             *
             * @param entity The Entity to link
             * @param type The type of the Component
             * @param ptr The shared_ptr to the Component
             */
            void linkEntityWithComponent(entity::Entity const &entity, component::ComponentType type, std::shared_ptr<component::Component> ptr);

            /**
             * @brief Link a Component to an Entity
             *
             * @tparam C The type of the Component
             * @tparam Params The parameters type needed to create the shared_ptr of Component
             * @param entity The Entity to link
             * @param params The parameters value needed to create the shared_ptr of Component
             * @return the created component
             */
            template<typename C, typename ...Params>
            std::shared_ptr<C> linkEntityWithComponent(entity::Entity const &entity, Params&&... params) {
                static_assert(std::is_base_of<component::Component, C>::value, "You need to pass a Component");
                auto component = std::make_shared<C>((params)...);
                linkEntityWithComponent(entity, C::type, component);
                return component;
            }

            /**
             * @brief Unlink a Component to an Entity
             *
             * @param entity The Entity to unlink
             * @param type The type of the Component to unlink
             */
            void unlinkEntityWithComponent(entity::Entity const &entity, component::ComponentType type);

            /**
             * @brief Link an Entity with an ISystem
             *
             * @param entity The Entity to link
             * @param type The SystemType of the stored ISystem
             */
            void linkEntityWithSystem(entity::Entity const &entity, system::SystemType type);

            /**
             * @brief Link an Entity with an ISystem
             *
             * @tparam S The type of the ISystem
             * @param entity The Entity to link
             */
            template<typename S>
            void linkEntityWithSystem(entity::Entity const &entity) {
                static_assert(std::is_base_of<system::ISystem, S>::value, "You need to pass a System");
                linkEntityWithSystem(entity, S::type);
            }

            /**
             * @brief Unlink an Entity with an ISystem
             *
             * @param entity The Entity to unlink
             * @param type The SystemType of the stored ISystem
             */
            void unlinkEntityWithSystem(entity::Entity const &entity, system::SystemType type);

            /**
             * @brief Unlink an Entity with an ISystem
             *
             * @tparam S The type of the ISystem
             * @param entity The Entity to unlink
             */
            template<typename S>
            void unlinkEntityWithSystem(entity::Entity const &entity) {
                static_assert(std::is_base_of<system::ISystem, S>::value, "You need to pass a System");
                unlinkEntityWithSystem(entity, S::type);
            }

            /**
             * @brief Load an ISystem to update Entity's Component values
             *
             * @param system The ISystem to load
             */
            void loadSystem(system::SystemType type, std::shared_ptr<system::ISystem> const &system);

            /**
             * @brief Load an ISystem to update Entity's Component values
             *
             * @tparam S The type of the ISystem to use
             * @tparam Params The parameters type needed to create the ISystem
             * @param params The parameters value needed to create the ISystem
             */
            template<typename S, typename ...Params>
            void loadSystem(Params&&... params) {
                static_assert(std::is_base_of<system::ISystem, S>::value, "You need to pass a System");
                loadSystem(S::type, std::make_shared<S>((params)...));
            }

            /**
             * @brief Add en Event
             *
             * @param event The Event to add
             */
            void dispatchEvent(event::Event const &event);

            /**
             * @brief Subscribe to event
             *
             * @param event event to listen
             * @param callback callback
             */
            void subscribeTo(event::Event const &event, event::EventCallback callback);

            /**
             * @brief Update all Entity's Component values
             *
             * @param delta The deltatime since last update
             */
            void update(float const &delta);

            /**
             * @brief Check if the GameEngine has a specific ComponentStorage
             *
             * @param type the type of the Component stored
             * @return true on success
             * @return false on failure
             */
            bool hasComponentStorage(component::ComponentType type);

            /**
             * @brief Check if the GameEngine has a specific ComponentStorage
             *
             * @tparam C the type of the Component stored
             * @return true on success
             * @return false on failure
             */
            template<typename C>
            bool hasComponentStorage() {
                static_assert(std::is_base_of<component::Component, C>::value, "You need to pass a Component");
                return hasComponentStorage(C::type);
            }

            private:
            /**
             * @brief The counter of the Entity to always have a unique id
             */
            entity::Entity _counter;

            /**
             * @brief Array of listeners
             */
            std::map<std::pair<event::EVENT_SENDER, event::EventType>, std::vector<event::EventCallback>> _listeners;

            /**
             * @brief The unordered_map of ComponentStorage to store multiple specific Component
             */
            std::unordered_map<component::ComponentType, component::ComponentStorage<component::Component>> _component_store;

            /**
             * @brief The vector of ISystem to update all Entity's Component
             */
            std::map<system::SystemType, std::shared_ptr<system::ISystem>> _systems;
        };
    }
}

#endif //CPP_RTYPE_2019_GAMEENGINE_HPP
