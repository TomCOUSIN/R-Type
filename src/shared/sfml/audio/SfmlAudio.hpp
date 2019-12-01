/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SFMLAUDIO_HPP
#define CPP_RTYPE_2019_SFMLAUDIO_HPP

#include <vector>
#include <memory>
#include <iostream>
#include "SoundEntity.hpp"
#include "GameEngine.hpp"
#include "InputEvent.hpp"
#include "IAudio.hpp"
#include "Sound.hpp"
#include "Music.hpp"

namespace rtype::sfml::audio {

    /**
     * @brief Handle Audio with SFML
     */
    class SfmlAudio : public rtype::audio::IAudio {

        public:
        /**
         * @brief Construct a SfmlAudio object
         *
         * @param engine The GameEngine to use
         */
        SfmlAudio(engine::GameEngine &engine);

        /**
         * @brief Destroy an IAudio object
         */
        ~SfmlAudio() final = default;

        /**
         * @brief Create a Sound Entity
         *
         * @param path the path to the sound
         * @param input_event the event when the sound need to be played
         * @return the Entity of the Sound
         */
        engine::entity::Entity createSound(std::string const &path, event::InputEvent::InputEventType const &input_event) final;

        /**
         * @brief Create a Sound Entity
         * @param path the path to the sound
         * @return the Entity of the Sound
         */
        engine::entity::Entity createSound(std::string const &path) final;

        /**
         * @brief Create a Music Entity
         * @param path the path to the Music
         * @return the Entity of the Music
         */
        engine::entity::Entity createMusic(std::string const &path) final;

        /**
         * @brief Play the sound or the music
         *
         * @param entity the Entity to play
         */
        void play(engine::entity::Entity const &entity) final;

        /**
         * @brief Stop the sound or the music
         *
         * @param entity the Entity to stop
         */
        void stop(engine::entity::Entity const &entity) final;

        /**
         * @brief Pause the sound or the music
         *
         * @param entity the Entity to pause
         */
        void pause(engine::entity::Entity const &entity) final;

        /**
         * @brief Loop the sound or the music
         *
         * @param entity the Entity to loop
         */
        void loop(engine::entity::Entity const &entity) final;

        /**
         * @brief Destroy the sound or the music
         *
         * @param entity the Entity to destroy
         */
        void destroy(engine::entity::Entity const &entity) final;

        private:
        /**
         * @brief The GameEngine to use
         */
        engine::GameEngine &_engine;

        /**
         * @brief the vector of SoundEntity
         */
        std::vector<std::shared_ptr<rtype::sfml::entity::SoundEntity>> _sounds;
    };
}

#endif //CPP_RTYPE_2019_SFMLAUDIO_HPP
