/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_IENTITYLOADER_HPP
#define CPP_RTYPE_2019_IENTITYLOADER_HPP

#include "GameEngine.hpp"

namespace rtype::engine {
    class GameEngine;
};

namespace rtype::engine::loader {

    /**
     * @brief Class that handle the creation of an Entity
     */
    class IEntityLoader {

        public:
        /**
         * @brief Destroy an IEntityLoader
         */
        virtual ~IEntityLoader() = default;

        /**
         * @brief Load an Entity with the GameEngine
         *
         * @param engine The GAmeEngine to use
         */
        virtual void loadEntity(rtype::engine::GameEngine &engine) = 0;
    };
}

#endif //CPP_RTYPE_2019_IENTITYLOADER_HPP
