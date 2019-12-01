/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SOUND_HPP
#define CPP_RTYPE_2019_SOUND_HPP

#include <iostream>
#include <SFML/Audio.hpp>
#include "Component.hpp"

namespace rtype::sfml::component {

    /**
     * @brief SFML Sound Component
     */
    struct Sound : public rtype::engine::component::Component {

        /**
         * @brief Construct a Sound object
         *
         * @param path The path to the sound
         */
        explicit Sound(std::string const &path) {
            if (buffer.loadFromFile(path)) {
                sound.setBuffer(buffer);
            }
        };

        /**
         *  @brief play the sound
         */
        void play() {
            sound.play();
        }

        /**
         *  @brief stop the sound
         */
        void stop() {
            sound.stop();
        }

        /**
         *  @brief pause the sound
         */
        void pause() {
            sound.pause();
        }

        /**
         *  @brief loop the sound
         */
        void loop() {
            sound.setLoop(true);
        }

        /**
         * @brief The sound
         */
        sf::Sound sound;

        /**
         * @brief The buffer of the sound
         */
        sf::SoundBuffer buffer;

        /**
         * @brief The type of the Component Sound
         */
        static const engine::component::ComponentType type = 1 << engine::component::COMPONENT_TYPE::SOUND;
    };
}

#endif //CPP_RTYPE_2019_SOUND_HPP
