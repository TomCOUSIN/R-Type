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
#include "Game.hpp"

namespace rtype::game {

Game::Game(engine::GameEngine &engine
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
    _scenes.emplace(std::pair(engine::scene::GAME, new scene::GameScene(_graphic, _audio, _network, framerate)));
    _graphic.init();
}

void Game::start()
{
    _actual_scene = _scenes.find(0)->second;
    _actual_scene->loadScene();
    loop();
}

void Game::changeScene(size_t const &id)
{
    _actual_scene->unloadScene();
    _actual_scene = _scenes.find(id)->second;
    _actual_scene->loadScene();
}

void Game::loop()
{
    while (_graphic.isWindowOpen()) {
        auto redirected_scene = _actual_scene->displayScene();
        if (redirected_scene == engine::scene::QUIT) {
            break;
        }
        changeScene(redirected_scene);
    }
}

void Game::stop()
{
    for (auto &scene : _scenes) {
        scene.second->unloadScene();
    }
}

}
