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
#include "ClientNetwork.hpp"
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
         * @param audio The IAudio to use
         * @param network The ClientNetwork to use
         * @param framerate The frame rate to use
         */
        explicit GameScene(graphic::IGraphic &graphic, audio::IAudio &audio, client::ClientNetwork &network, std::size_t framerate);

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
         * @brief Scene framerate
         */
        std::size_t _framerate;

        /**
         * @brief the IAudio to use
         */
        audio::IAudio &_audio;

        /**
         * @brief the ClientNetwork to use
         */
        client::ClientNetwork &_network;

        /**
         * @brief the IGraphic to use
         */
        graphic::IGraphic &_graphic;

        /**
         * @brief The list of Entity
         */
        std::unordered_map<std::string, engine::entity::Entity> _entities;
    };
}

#endif //CPP_RTYPE_2019_GAMESCENE_HPP
