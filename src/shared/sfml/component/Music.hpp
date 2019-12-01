/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_MUSIC_HPP
#define CPP_RTYPE_2019_MUSIC_HPP

#include <iostream>
#include <SFML/Audio.hpp>
#include "Component.hpp"

namespace rtype::sfml::component {

    /**
     * @brief SFML Music Component
     */
    struct Music : public rtype::engine::component::Component {

        /**
         * @brief Construct a Music object
         *
         * @param path The path to the music
         */
        Music(std::string const &path) {
            music.openFromFile("path");
        };

        /**
         *  @brief play the music
         */
        void play() {
            music.play();
        }

        /**
         *  @brief stop the music
         */
        void stop() {
            music.stop();
        }

        /**
         *  @brief pause the music
         */
        void pause() {
            music.pause();
        }

        /**
         *  @brief loop the music
         */
        void loop() {
            music.setLoop(true);
        }

        /**
         * @brief The music
         */
        sf::Music music;

        /**
         * @brief The type of the Component Music
         */
        static const engine::component::ComponentType type = 1 << engine::component::COMPONENT_TYPE::MUSIC;
    };
}

#endif //CPP_RTYPE_2019_MUSIC_HPP
