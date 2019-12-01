/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "SoundEntity.hpp"

const rtype::engine::entity::EntityType rtype::sfml::entity::SoundEntity::type = 1 << engine::entity::ENTITY_TYPE::SOUND;

rtype::sfml::entity::SoundEntity::SoundEntity(rtype::engine::GameEngine &engine
    , std::string const &path
    , event::InputEvent::InputEventType const &input_event) :
engine::entity::EntityCreator(engine),
_sound(std::make_shared<sfml::component::Sound>(path))
{
    engine.loadComponentStorage<sfml::component::Sound>();

    _sound_entity = engine.createEntity();

    engine.linkEntityWithComponent(_sound_entity, sfml::component::Sound::type, _sound);

    engine.subscribeTo(
        event::InputEvent(input_event),
        std::bind(&SoundEntity::onPlay, this, std::placeholders::_1)
    );
}

rtype::engine::entity::Entity rtype::sfml::entity::SoundEntity::getSoundEntity() const
{
    return _sound_entity;
}

void rtype::sfml::entity::SoundEntity::onPlay(const rtype::engine::event::Event &event)
{
    _sound->stop();
    _sound->play();
}
