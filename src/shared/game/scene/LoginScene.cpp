/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <iostream>
#include <thread>

#include "LoginScene.hpp"

namespace rtype::game::scene {

LoginScene::LoginScene(graphic::IGraphic &graphic
                                          , audio::IAudio &audio
                                          , client::ClientNetwork &network
                                          , std::size_t framerate)
    : _graphic(graphic)
    , _audio(audio)
    , _network(network)
    , _framerate(framerate)
{}

void LoginScene::loadScene()
{
    _entities.emplace(std::pair("title", _graphic.createText("Login", 50)));
    _graphic.setPosition(_entities["title"], 960.0f, 100.0f);
    _graphic.setVisible(_entities["title"], true);
    _entities.emplace(std::pair("server_ip", _graphic.createInput("Server IP", 960, 400, 200, 70, [this](std::string value) { _server_ip = value; })));
    _entities.emplace(std::pair("port", _graphic.createInput("Port", 960, 500, 200, 70, [this](std::string value) { _server_port = value; })));
    _entities.emplace(std::pair("username", _graphic.createInput("Username", 960, 600, 200, 70, [this](std::string value) { _username = value; })));
    _entities.emplace(std::pair("connect", _graphic.createButton("Connect", 960, 800, 200, 100, [this]{ connect(); })));
}

rtype::engine::scene::SCENE LoginScene::displayScene()
{
    while (_graphic.isWindowOpen() && !_network.isConnected()) {
        _graphic.update(_framerate);
        std::this_thread::sleep_for(std::chrono::milliseconds(_framerate));
    }
    return rtype::engine::scene::MENU;
}

void LoginScene::unloadScene()
{
    for (auto &entity : _entities) {
        _graphic.removeElement(entity.second);
    }
    _entities.clear();
}

void LoginScene::connect()
{
    try {
        std::size_t port = std::stoi(_server_port);
        _network.connect(_server_ip, port, _username);
    } catch (std::exception) {
        std::cerr << "fail to connect to (" << _server_ip << ":" << _server_port << ")" << std::endl;
    }
}

}
