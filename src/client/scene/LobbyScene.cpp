/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by lucasmrdt,
*/

#include <iostream>
#include <thread>

#include "LobbyScene.hpp"

namespace rtype::client::scene {

LobbyScene::LobbyScene(graphic::IGraphic &graphic
                                          , audio::IAudio &audio
                                          , client::ClientNetwork &network
                                          , std::size_t framerate)
    : _graphic(graphic)
    , _audio(audio)
    , _network(network)
    , _framerate(framerate)
{}

void LobbyScene::loadScene()
{
    _back = false;
    // @todo create TextEntity
    _entities.emplace(std::pair("title", _graphic.createText("Lobby", 50)));
    _graphic.setPosition(_entities["title"], 960.0f, 100.0f);
    _graphic.setVisible(_entities["title"], true);
    _entities.emplace(std::pair("back", _graphic.createButton("Back", 200, 100, 200, 100, [this]() { _back = true; })));
    _entities.emplace(std::pair("target_username", _graphic.createInput("Target username", 960, 400, 200, 70, [this](std::string value) { _target_session_user = value; })));
    _entities.emplace(std::pair("join", _graphic.createButton("Join", 960, 500, 200, 100, [this]{ joinSession(); })));
    _entities.emplace(std::pair("or", _graphic.createText("or", 20)));
    _graphic.setPosition(_entities["or"], 960.0f, 650.0f);
    _graphic.setVisible(_entities["or"], true);
    _entities.emplace(std::pair("create", _graphic.createButton("Create", 960, 800, 200, 100, [this]{ createSession(); })));
}

rtype::engine::scene::SCENE LobbyScene::displayScene()
{
    while (_graphic.isWindowOpen() && !_network.hasJoinedSession() && !_back) {
        _graphic.update(_framerate);
        std::this_thread::sleep_for(std::chrono::milliseconds(_framerate));
    }
    return _back ? engine::scene::MENU : rtype::engine::scene::GAME;
}

void LobbyScene::unloadScene()
{
    for (auto &entity : _entities) {
        _graphic.removeElement(entity.second);
    }
    _entities.clear();
}

void LobbyScene::joinSession()
{
    if (_target_session_user.size() == 0) {
        std::cerr << "you must provide a target username to join a session" << std::endl;
        return;
    }
    _network.joinSession(_target_session_user);
}

void LobbyScene::createSession()
{
    _network.createSession();
}

}
