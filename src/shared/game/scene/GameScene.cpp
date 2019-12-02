/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <thread>

#include "GameScene.hpp"
#include "InputEvent.hpp"

namespace rtype::game::scene {

GameScene::GameScene(graphic::IGraphic &graphic
                                        , audio::IAudio &audio
                                        , client::ClientNetwork &network
                                        , std::size_t framerate)
    : _graphic(graphic)
    , _audio(audio)
    , _network(network)
    , _framerate(framerate)
{}

void GameScene::loadScene()
{
    _entities.emplace(std::pair("level", _audio.createMusic("./assets/sounds/level1.ogg")));
    _entities.emplace("parallax", _graphic.createParallax("./assets/parallax/Background.jpg", "./assets/parallax/Foreground.png", 2));
    _entities.emplace("sprite", _graphic.createSprite("./assets/spaceship.gif", 300, 300, 33, 17, 3, 3, 1, true, 10, 10, true));
    _entities.emplace("shot_sound", _audio.createSound("./assets/sounds/shot.wav", rtype::sfml::event::InputEvent::InputEventType::SPACE));
    _entities.emplace("shot_sound", _audio.createSound("./assets/sounds/shot.wav", rtype::sfml::event::InputEvent::InputEventType::SPACE));
    _audio.play(_entities["level"]);
}

rtype::engine::scene::SCENE GameScene::displayScene()
{
    while (_graphic.isWindowOpen()) {
        _graphic.update(_framerate);
        std::this_thread::sleep_for(std::chrono::milliseconds(_framerate));
    }
    return rtype::engine::scene::MENU;
}

void GameScene::unloadScene()
{
    _audio.stop(_entities["level"]);
    for (auto &entity : _entities) {
        _graphic.removeElement(entity.second);
    }
    _entities.clear();
}

}
