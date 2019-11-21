/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_COMPONENTMANAGER_HPP
#define CPP_RTYPE_2019_COMPONENTMANAGER_HPP

#include <iostream>
#include <unordered_map>

namespace rtype {

    namespace engine {

        namespace component {

            template <class C>
            class ComponentManager {

                // @MARK Public
                public:

                // @MARK Constructor / Destructor
                ComponentManager() = default;
                ~ComponentManager() = default;

                // @MARK Getter
                /**
                 * @brief Get the component list of the ComponentManager
                 *
                 * @tparam C The component stored int the list
                 * @return The component list of the ComponentManager
                 */
                std::unordered_map<unsigned long, C> getComponentList() const {
                    return _component_list;
                }

                // @MARK Methods
                /**
                 * @brief Link a component with an Entity
                 *
                 * @tparam C The Component stored in the ComponentManager
                 * @param entity_id The unique_id of the Entity to link with
                 * @param component The component to link with
                 * @return True on success
                 * @return False on failure
                 */
                bool addComponentToEntity(const unsigned long &entity_id, const C &component) {
                    if (_component_list.find(entity_id) == _component_list.end()) {
                        _component_list.emplace(std::pair<unsigned long, C>(entity_id, component));
                        return true;
                    }
                    else {
                        return false;
                    }
                }

                /**
                 * @brief Unlink a component with an Entity
                 *
                 * @tparam C The Component stored in the ComponentManager
                 * @param entity_id The unique_id of the Entity to unlink
                 * @return True on success
                 * @return False on failure
                 */
                bool removeComponentByEntity(const unsigned long &entity_id) {
                    if (_component_list.find(entity_id) != _component_list.end()) {
                        _component_list.erase(_component_list.find(entity_id));
                        return true;
                    }
                    else {
                        return false;
                    }
                }

                // @MARK Private
                private:

                // @MARK Attributes
                std::unordered_map<unsigned long, C> _component_list;

            };
        }
    }
}

#endif //CPP_RTYPE_2019_COMPONENTMANAGER_HPP
