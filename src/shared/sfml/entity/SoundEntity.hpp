/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SOUNDENTITY_HPP
#define CPP_RTYPE_2019_SOUNDENTITY_HPP

#include <memory>
#include "EntityCreator.hpp"
#include "InputEvent.hpp"
#include "Sound.hpp"

namespace rtype::sfml::entity {

    class SoundEntity : engine::entity::EntityCreator {

        public:
        /**
         * @brief Construct a new SoundEntity Entity
         */
        SoundEntity(engine::GameEngine &engine
            , std::string const &path
            , event::InputEvent::InputEventType const &input_event);

        /**
         * @brief Get the Entity of the Sprite
         * @return
         */
        engine::entity::Entity getSoundEntity() const;

        /**
         * @brief When the sound need to be played
         */
        void onPlay(engine::event::Event const &event);

        /**
         * @brief The type of the Created Entity
         */
        static const engine::entity::EntityType type;

        private:
        /**
         * @brief The Entity of the Sprite
         */
        engine::entity::Entity _sound_entity;

        /**
         * @brief The sound of the SoundEntity
         */
        std::shared_ptr<sfml::component::Sound> _sound;
    };
}

#endif //CPP_RTYPE_2019_SOUNDENTITY_HPP
