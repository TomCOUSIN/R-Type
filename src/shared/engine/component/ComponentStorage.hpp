/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_COMPONENTSTORAGE_HPP
#define CPP_RTYPE_2019_COMPONENTSTORAGE_HPP

#include <iostream>
#include <unordered_map>
#include "Component.hpp"
#include "Entity.hpp"

namespace rtype {

    namespace engine {

        namespace component {

            /**
             * @brief A ComponentStorage class that store a specific Component
             *
             * @tparam C The Component to store
             */
            template <typename C>
            class ComponentStorage {

                public:
                /**
                 * @brief Construct a new ComponentStorage object
                 */
                ComponentStorage() = default;

                /**
                 * @brief Destroy a ComponentStorage
                 */
                ~ComponentStorage() = default;

                /**
                 * @brief Add a new Entity to link the the Component
                 *
                 * @param entity The Entity to link with
                 * @param component The Component to link with
                 * @return true on success
                 * @return false on failure
                 */
                bool addEntity(entity::Entity const &entity, C const &component) {
                    if (_store.find(entity) == _store.end()) {
                        _store.emplace(std::make_pair(entity, component));
                        return true;
                    }
                    else {
                        return false;
                    }
                }

                /**
                 * @brief Remove an Entity linked to a Component
                 *
                 * @param entity The Entity to remove
                 * @return true on success
                 * @return false on failure
                 */
                bool removeEntity(entity::Entity const &entity) {
                    if (_store.find(entity) == _store.end()) {
                        return false;
                    }
                    else {
                        _store.erase(_store.find(entity));
                        return true;
                    }
                }

                /**
                 * @brief Check if an Entity is linked to a Component
                 *
                 * @param entity The Entity to check
                 * @return true on success
                 * @return false on failure
                 */
                bool entityHasComponent(entity::Entity const &entity) {
                    return _store.find(entity) != _store.end();
                }

                /**
                 * @brief Get a Component linked to an Entity
                 *
                 * @param entity The Entity linked with the Component
                 * @return A pointer to the Component on success
                 * @return Null on failure
                 */
                C getComponent(entity::Entity const &entity) {
                    auto iterator = _store.find(entity);
                    return iterator->second;
                }

                private:
                /**
                 * @brief The storage of the ComponentStorage
                 */
                std::unordered_map<entity::Entity, C> _store;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_COMPONENTSTORAGE_HPP