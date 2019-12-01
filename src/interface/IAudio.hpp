/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_IAUDIO_HPP
#define CPP_RTYPE_2019_IAUDIO_HPP

#include <iostream>
#include "Entity.hpp"
#include "InputEvent.hpp"

namespace rtype::audio {

    /**
     * @brief IAudio to handle sound and music
     */
    class IAudio {

        public:
        /**
         * @brief Destroy an IAudio object
         */
        virtual ~IAudio() = default;

        /**
         * @brief Create a Sound Entity
         *
         * @param path the path to the sound
         * @param input_event the event when the sound need to be played
         * @return the Entity of the Sound
         */
        virtual engine::entity::Entity createSound(std::string const &path, rtype::sfml::event::InputEvent::InputEventType const &input_event) = 0;

        /**
         * @brief Create a Sound Entity
         * @param path the path to the sound
         * @return the Entity of the Sound
         */
        virtual engine::entity::Entity createSound(std::string const &path) = 0;

        /**
         * @brief Create a Music Entity
         * @param path the path to the Music
         * @return the Entity of the Music
         */
        virtual engine::entity::Entity createMusic(std::string const &path) = 0;

        /**
         * @brief Play the sound or the music
         *
         * @param entity the Entity to play
         */
        virtual void play(engine::entity::Entity const &entity) = 0;

        /**
         * @brief Stop the sound or the music
         *
         * @param entity the Entity to stop
         */
        virtual void stop(engine::entity::Entity const &entity) = 0;

        /**
         * @brief Pause the sound or the music
         *
         * @param entity the Entity to pause
         */
        virtual void pause(engine::entity::Entity const &entity) = 0;

        /**
         * @brief Loop the sound or the music
         *
         * @param entity the Entity to loop
         */
        virtual void loop(engine::entity::Entity const &entity) = 0;

        /**
         * @brief Destroy the sound or the music
         *
         * @param entity the Entity to destroy
         */
        virtual void destroy(engine::entity::Entity const &entity) = 0;

    };
}

#endif //CPP_RTYPE_2019_IAUDIO_HPP
