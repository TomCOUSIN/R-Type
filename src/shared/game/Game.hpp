/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_GAME_HPP
#define CPP_RTYPE_2019_GAME_HPP

#include <iostream>
#include <unordered_map>
#include "GameEngine.hpp"
#include "IGraphic.hpp"
#include "IScene.hpp"
#include "ITimer.hpp"

namespace rtype::game {

    /**
     * @brief The Game class to handle the game
     */
    class Game {

        public:
        /**
         * @brief Construct a Game object
         */
        Game();

        /**
         * @brief Destroy a Game object
         */
        ~Game() = default;

        /**
         * @brief Start the Game
         */
        void start();

        /**
         * @brief Stop the Game
         */
        void stop();

        /**
         * @brief Change the actual scene
         *
         * @param id The id of the new scene
         */
        void changeScene(size_t const &id);

        private:

        /**
         * @brief The main loop of the game
         */
        void loop();

        /**
         * @brief The GameEngine to use
         */
        engine::GameEngine _engine;

        /**
         * @brief The ITimer to use
         */
        std::shared_ptr<rtype::timer::ITimer> _timer;

        /**
         * @brief The IGraphic to use
         */
        std::shared_ptr<rtype::graphic::IGraphic> _graphic;

        /**
         * @brief The actual IScene
         */
        std::shared_ptr<engine::scene::IScene> _actual_scene;

        /**
         * @brief The IScene of the game
         */
        std::unordered_map<size_t, std::shared_ptr<engine::scene::IScene>> _scenes;
    };
}

#endif //CPP_RTYPE_2019_GAME_HPP
