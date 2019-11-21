/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_ENTITYMANAGER_HPP
#define CPP_RTYPE_2019_ENTITYMANAGER_HPP

#include <vector>
#include <iostream>
#include "Entity.hpp"

namespace rtype {

    namespace engine {

        namespace entity {

            class EntityManager {

                // @MARK Public
                public:

                // @MARK Constructor / Destructor
                EntityManager();
                ~EntityManager() = default;

                // @MARK PUBLIC Methods
                Entity createNewEntity();
                bool removeEntity(unsigned long entity_id);

                // @MARK Private
                private:

                // @MARK PRIVATE Methods
                unsigned long generateUniqueId();

                // @MARK Attributes
                unsigned long _id_counter;
                std::vector<Entity> _entity_list;
                std::vector<unsigned long> _available_unique_id;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_ENTITYMANAGER_HPP
