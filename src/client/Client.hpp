/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_CLIENT_HPP
#define CPP_RTYPE_2019_CLIENT_HPP

#include <iostream>
#include <unordered_map>
#include "GameEngine.hpp"
#include "IGraphic.hpp"
#include "IScene.hpp"
#include "IAudio.hpp"
#include "ClientNetwork.hpp"

namespace rtype::client {

    /**
     * @brief The Client class to handle the game
     */
    class Client {

        public:
        /**
         * @brief Construct a Client object
         */
        Client(engine::GameEngine &engine, graphic::IGraphic &graphic, audio::IAudio &audio, client::ClientNetwork &network, std::size_t framerate);

        /**
         * @brief Destroy a Client object
         */
        ~Client() = default;

        /**
         * @brief Start the Client
         */
        void start();

        /**
         * @brief Stop the Client
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
        engine::GameEngine &_engine;

        /**
         * @brief The IGraphic to use
         */
        graphic::IGraphic &_graphic;

        /**
         * @brief The IAudio to use
         */
        audio::IAudio &_audio;

        /**
         * @brief The ClientNetwork to use
         */
        client::ClientNetwork &_network;

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

#endif //CPP_RTYPE_2019_CLIENT_HPP
