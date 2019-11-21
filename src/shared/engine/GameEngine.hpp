/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_GAMEENGINE_HPP
#define CPP_RTYPE_2019_GAMEENGINE_HPP

#include <iostream>
#include "IGameEngine.hpp"

namespace rtype {

    namespace engine {

        class GameEngine : public IGameEngine {

            // @MARK Public
            public:

            // @MARK Constructor / Destructor
            GameEngine() = default;
            ~GameEngine() final = default;
        };
    }
}

#endif //CPP_RTYPE_2019_GAMEENGINE_HPP
