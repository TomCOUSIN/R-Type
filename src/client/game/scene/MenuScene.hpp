/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_MENUSCENE_HPP
#define CPP_RTYPE_2019_MENUSCENE_HPP

#include <iostream>
#include <unordered_map>
#include "IGraphic.hpp"
#include "IScene.hpp"
#include "ITimer.hpp"
#include "Entity.hpp"

namespace rtype::game::scene {

    class MenuScene : public engine::scene::IScene {

        public:
        /**
         * @brief Construct a MenuScene object
         *
         * @param graphic The IGraphic to use
         * @param timer The ITimer to use
         */
        explicit MenuScene(std::shared_ptr<graphic::IGraphic> graphic);

        /**
         * @brief Destroy an MenuScene object
         */
        ~MenuScene() final = default;

        /**
         *  @brief The Scene loads everything needed for it to run properly
         */
        void loadScene() final;

        /**
         *  @brief Display the scene by using the engine
         */
        void displayScene(float const &delta) final;

        /**
         *  @brief Unload the scene by removing entity, Component and ISystem in the GameEngine
         */
        void unloadScene() final;


        private:
        /**
         * @brief the IGraphic to use
         */
        std::shared_ptr<graphic::IGraphic> _graphic;

        /**
         * @brief The list of Entity
         */
        std::unordered_map<std::string, engine::entity::Entity> _entities;
    };
}

#endif //CPP_RTYPE_2019_MENUSCENE_HPP
