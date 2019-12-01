/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "SfmlAudio.hpp"
#include "Sound.hpp"
#include "Music.hpp"

rtype::sfml::audio::SfmlAudio::SfmlAudio(rtype::engine::GameEngine &engine) :
_engine(engine)
{
    _engine.loadComponentStorage(sfml::component::Sound::type);
    _engine.loadComponentStorage(sfml::component::Music::type);
}

rtype::engine::entity::Entity rtype::sfml::audio::SfmlAudio::createSound(
    std::string const &path
    , const rtype::sfml::event::InputEvent::InputEventType &input_event)
{
    _sounds.emplace_back(std::make_shared<sfml::entity::SoundEntity>(_engine, path, input_event));
    return _sounds.back()->getSoundEntity();
}

rtype::engine::entity::Entity rtype::sfml::audio::SfmlAudio::createSound(std::string const &path)
{
    auto entity = _engine.createEntity();

    _engine.linkEntityWithComponent<sfml::component::Sound>(entity, path);
    return entity;
}

rtype::engine::entity::Entity rtype::sfml::audio::SfmlAudio::createMusic(std::string const &path)
{
    auto entity = _engine.createEntity();

    _engine.linkEntityWithComponent<sfml::component::Music>(entity, path);
    return entity;
}

void rtype::sfml::audio::SfmlAudio::play(const rtype::engine::entity::Entity &entity)
{
    auto music_store = _engine.getComponentStorage<sfml::component::Music>();
    auto sound_store = _engine.getComponentStorage<sfml::component::Sound>();

    if (music_store.entityHasComponent(entity)) {
        music_store.getComponent<sfml::component::Music>(entity)->play();
    }
    if (sound_store.entityHasComponent(entity)) {
        music_store.getComponent<sfml::component::Sound>(entity)->play();
    }
}

void rtype::sfml::audio::SfmlAudio::stop(const rtype::engine::entity::Entity &entity)
{
    auto music_store = _engine.getComponentStorage<sfml::component::Music>();
    auto sound_store = _engine.getComponentStorage<sfml::component::Sound>();

    if (music_store.entityHasComponent(entity)) {
        music_store.getComponent<sfml::component::Music>(entity)->stop();
    }
    if (sound_store.entityHasComponent(entity)) {
        music_store.getComponent<sfml::component::Sound>(entity)->stop();
    }
}

void rtype::sfml::audio::SfmlAudio::pause(const rtype::engine::entity::Entity &entity)
{
    auto music_store = _engine.getComponentStorage<sfml::component::Music>();
    auto sound_store = _engine.getComponentStorage<sfml::component::Sound>();

    if (music_store.entityHasComponent(entity)) {
        music_store.getComponent<sfml::component::Music>(entity)->pause();
    }
    if (sound_store.entityHasComponent(entity)) {
        music_store.getComponent<sfml::component::Sound>(entity)->pause();
    }
}

void rtype::sfml::audio::SfmlAudio::loop(const rtype::engine::entity::Entity &entity)
{
    auto music_store = _engine.getComponentStorage<sfml::component::Music>();
    auto sound_store = _engine.getComponentStorage<sfml::component::Sound>();

    if (music_store.entityHasComponent(entity)) {
        music_store.getComponent<sfml::component::Music>(entity)->loop();
    }
    if (sound_store.entityHasComponent(entity)) {
        music_store.getComponent<sfml::component::Sound>(entity)->loop();
    }
}

void rtype::sfml::audio::SfmlAudio::destroy(const rtype::engine::entity::Entity &entity)
{
    _engine.destroyEntity(entity);
}
