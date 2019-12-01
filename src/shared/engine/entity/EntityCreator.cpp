/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#include "EntityCreator.hpp"

namespace rtype::engine::entity {

const EntityType EntityCreator::type = 0;

EntityCreator::EntityCreator(GameEngine &game_engine):
    _game_engine(game_engine)
{
}

}
