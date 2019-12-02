/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <iostream>
#include <thread>

#include "MenuScene.hpp"

namespace rtype::client::scene {

MenuScene::MenuScene(graphic::IGraphic &graphic
                    , audio::IAudio &audio
                    , client::ClientNetwork &network
                    , std::size_t framerate)
    : _graphic(graphic)
    , _audio(audio)
    , _network(network)
    , _framerate(framerate)
{}

void MenuScene::loadScene()
{
    _quit = false;
    _play = false;
    _entities.emplace(std::pair("main_theme", _audio.createMusic("./assets/sounds/main_theme.ogg")));
    _audio.play(_entities["main_theme"]);
    _entities.emplace(std::pair("title", _graphic.createText("R-Type", 50)));
    _graphic.setPosition(_entities["title"], 960.0f, 100.0f);
    _graphic.setVisible(_entities["title"], true);
    _entities.emplace(std::pair("play", _graphic.createButton("Play", 960, 400, 200, 100, [this]{_play = true;})));
    _entities.emplace(std::pair("quit", _graphic.createButton("Quit", 960, 600, 200, 100, [this]{_quit = true;})));
}

engine::scene::SCENE MenuScene::displayScene()
{
    while (_graphic.isWindowOpen() && !_play && !_quit) {
        _graphic.update(_framerate);
        std::this_thread::sleep_for(std::chrono::milliseconds(_framerate));
    }
    return _play ? engine::scene::LOBBY : engine::scene::QUIT;
}

void MenuScene::unloadScene()
{
    _audio.stop(_entities["main_theme"]);
    for (auto &entity : _entities) {
        _graphic.removeElement(entity.second);
    }
    _entities.clear();
}

}
