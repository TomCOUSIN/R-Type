/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_GAMEENGINE_HPP
#define CPP_RTYPE_2019_GAMEENGINE_HPP

#include <vector>
#include <iostream>
#include <unordered_map>
#include "ComponentManager.hpp"
#include "MovementSystem.hpp"
#include "EntityManager.hpp"
#include "IGameEngine.hpp"
#include "Direction.hpp"
#include "Position.hpp"
#include "ISystem.hpp"
#include "Speed.hpp"

namespace rtype {

    namespace engine {

        class GameEngine : public IGameEngine {

            // @MARK Public
            public:

            // @MARK Constructor / Destructor
            GameEngine();
            ~GameEngine() final = default;

            // @MARK Methods
            void update() final;
            void createEntity(std::string const &entity_name) final;
            void destroyEntity(std::string const &entity_name) final;

            // @MARK Getter
            std::unordered_map<std::string, unsigned long> getEntitys() const final;

            // @MARK Private
            private:

            // @MARK Attributes
            entity::EntityManager _entity_manager;

            // TODO Create a vector of ComponentManager
            component::ComponentManager<component::Position> _positions;
            component::ComponentManager<component::Direction> _directions;
            component::ComponentManager<component::Speed> _speeds;

            std::vector<std::unique_ptr<system::ISystem>> _systems;

            std::unordered_map<std::string, unsigned long> _entitys;
        };
    }
}

#endif //CPP_RTYPE_2019_GAMEENGINE_HPP
