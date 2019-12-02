/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "MenuScene.hpp"
#include "LoginScene.hpp"
#include "LoginScene.hpp"
#include "LobbyScene.hpp"
#include "GameScene.hpp"
#include "Client.hpp"

namespace rtype::client {

Client::Client(engine::GameEngine &engine
          , graphic::IGraphic &graphic
          , audio::IAudio &audio
          , client::ClientNetwork &network
          , std::size_t framerate)
    : _engine(engine)
    , _graphic(graphic)
    , _audio(audio)
    , _network(network)
    , _actual_scene(nullptr)
    , _scenes()
{
    _scenes.emplace(std::pair(engine::scene::LOGIN, new scene::LoginScene(_graphic, _audio, _network, framerate)));
    _scenes.emplace(std::pair(engine::scene::MENU, new scene::MenuScene(_graphic, _audio, _network, framerate)));
    _scenes.emplace(std::pair(engine::scene::LOBBY, new scene::LobbyScene(_graphic, _audio, _network, framerate)));
    _scenes.emplace(std::pair(engine::scene::GAME, new scene::GameScene(_engine, _graphic, _audio, _network, framerate)));
    _graphic.init();
}

void Client::start()
{
    _actual_scene = _scenes.find(0)->second;
    _actual_scene->loadScene();
    loop();
}

void Client::changeScene(size_t const &id)
{
    _actual_scene->unloadScene();
    _actual_scene = _scenes.find(id)->second;
    _actual_scene->loadScene();
}

void Client::loop()
{
    while (_graphic.isWindowOpen()) {
        auto redirected_scene = _actual_scene->displayScene();
        if (redirected_scene == engine::scene::QUIT) {
            break;
        }
        changeScene(redirected_scene);
    }
}

void Client::stop()
{
    for (auto &scene : _scenes) {
        scene.second->unloadScene();
    }
}

}
