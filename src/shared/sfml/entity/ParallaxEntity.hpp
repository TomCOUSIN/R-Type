/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_PARALLAXENTITY_HPP
#define CPP_RTYPE_2019_PARALLAXENTITY_HPP

#include <iostream>
#include <functional>
#include "EntityCreator.hpp"
#include "Position.hpp"

namespace rtype::sfml::entity {

    class ParallaxEntity : public engine::entity::EntityCreator {

        public:
        /**
         * @brief Construct a Parallax Entity
         */
        ParallaxEntity(engine::GameEngine &game_engine
        , std::string const &background_path
        , std::string const &foreground_path
        , float const &background_speed_x);
    };
}

#endif //CPP_RTYPE_2019_PARALLAXENTITY_HPP
