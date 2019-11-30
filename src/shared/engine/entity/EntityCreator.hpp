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

    // @MARK Properties
        protected:
            GameEngine &_game_engine;

    };

}

#endif /* !ENTITYCREATOR_HPP_ */
