/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_IGAMEENGINE_HPP
#define CPP_RTYPE_2019_IGAMEENGINE_HPP

namespace rtype {

    namespace engine {

        class IGameEngine {

            // @MARK Public
            public:

            // @MARK Virtual destructor
            virtual ~IGameEngine() = default;

            // @MARK Methods
            virtual void update() = 0;
            virtual void createEntity(std::string const &entity_name) = 0;
            virtual void destroyEntity(std::string const &entity_name) = 0;
            virtual std::unordered_map<std::string, unsigned long> getEntitys() const = 0;
        };
    }
}

#endif //CPP_RTYPE_2019_IGAMEENGINE_HPP
