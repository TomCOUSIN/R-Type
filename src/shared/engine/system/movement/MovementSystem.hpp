/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_MOVEMENTSYSTEM_HPP
#define CPP_RTYPE_2019_MOVEMENTSYSTEM_HPP

#include "ComponentManager.hpp"
#include "Direction.hpp"
#include "Position.hpp"
#include "ISystem.hpp"
#include "Speed.hpp"

namespace rtype {

    namespace engine {

        namespace system {

            class MovementSystem : public ISystem {

                // @MARK Public
                public:

                // @MARK Constructor / Destructor
                MovementSystem(component::ComponentManager<component::Position> &position,
                                component::ComponentManager<component::Direction> &direction,
                                component::ComponentManager<component::Speed> &speed);
                ~MovementSystem() final = default;

                // @MARK PUBLIC Methods
                void update() final;

                // @MARK Private
                private:

                // @MARK PRIVATE Methods
                void updatePosition(unsigned long const &entity_id, component::Position &position);

                // @MARK Attributes
                component::ComponentManager<component::Position> &_position;
                component::ComponentManager<component::Direction> &_direction;
                component::ComponentManager<component::Speed> &_speed;

            };
        }
    }
}

#endif //CPP_RTYPE_2019_MOVEMENTSYSTEM_HPP
