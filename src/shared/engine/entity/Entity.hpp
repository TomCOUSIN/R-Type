/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_ENTITY_HPP
#define CPP_RTYPE_2019_ENTITY_HPP

namespace rtype {

    namespace engine {

        namespace entity {

            class Entity {

                // @MARK Public
                public:

                // @MARK Constructor / Destructor
                Entity(const unsigned long &unique_id);
                ~Entity() = default;

                // @MARK Getter
                unsigned long getUniqueId() const;

                // @MARK Setter
                void setUniqueId(const unsigned long &unique_id);

                // @MARK Private
                private:

                // @MARK Attributes
                unsigned long _unique_id;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_ENTITY_HPP
