/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_GAMESCENE_HPP
#define CPP_RTYPE_2019_GAMESCENE_HPP

#include <iostream>
#include <unordered_map>
#include "IGraphic.hpp"
#include "IAudio.hpp"
#include "IScene.hpp"
#include "ITimer.hpp"
#include "Entity.hpp"

namespace rtype::game::scene {

    /**
     * @brief The GameScene of the game
     */
    class GameScene : public engine::scene::IScene {

        public:
        /**
         * @brief Construct a GameScene object
         *
         * @param graphic The IGraphic to use
         * @param timer The ITimer to use
         */
        explicit GameScene(std::shared_ptr<graphic::IGraphic> graphic
            , std::shared_ptr<timer::ITimer> timer
            , std::shared_ptr<audio::IAudio> audio);

        /**
         * @brief Destroy an GameScene object
         */
        ~GameScene() final = default;

        /**
         *  @brief The Scene loads everything needed for it to run properly
         */
        void loadScene() final;

        /**
         *  @brief Display the scene by using the engine
         */
        rtype::engine::scene::SCENE displayScene() final;

        /**
         *  @brief Unload the scene by removing entity, Component and ISystem in the GameEngine
         */
        void unloadScene() final;


        private:
        /**
         * @brief the Iaudio to use
         */
        std::shared_ptr<audio::IAudio> _audio;

        /**
         * @brief the ITimer to use
         */
        std::shared_ptr<timer::ITimer> _timer;

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

#endif //CPP_RTYPE_2019_GAMESCENE_HPP
