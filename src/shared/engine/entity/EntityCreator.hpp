/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef ENTITYCREATOR_HPP_
#define ENTITYCREATOR_HPP_

#include "GameEngine.hpp"

namespace rtype::engine::entity {

    /**
     * @brief Define the EntityType
     */
    typedef unsigned long EntityType;

    /**
     * @brief ENTITY_TYPE
     */
    enum ENTITY_TYPE {
        BUTTON,
        MOUSE,
        PARALLAX,
        SPRITE,
        SOUND
    };

    class EntityCreator {

    // @MARK Constructors/Destructors
        public:
        /**
         * @brief Construct a new Entity Creator
         */
        EntityCreator(GameEngine &game_engine);

        /**
         * @brief Destroy the Entity Creator
         */
        ~EntityCreator() = default;

    // @MARK Static
        public:
        /**
         * @brief The type of the Created Entity
         */
        static const EntityType type;


    // @MARK Properties
        protected:
        GameEngine &_game_engine;

    };

}

#endif /* !ENTITYCREATOR_HPP_ */
