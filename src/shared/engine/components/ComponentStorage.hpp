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
