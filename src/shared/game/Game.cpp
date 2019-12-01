/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "SfmlGraphic.hpp"
#include "SfmlTimer.hpp"
#include "MenuScene.hpp"
#include "GameScene.hpp"
#include "Game.hpp"

rtype::game::Game::Game() :
_engine(),
_timer(new rtype::sfml::timer::SfmlTimer()),
_graphic(new rtype::sfml::graphic::SfmlGraphic(_engine)),
_actual_scene(nullptr),
_scenes()
{
    _scenes.emplace(std::pair(0, new rtype::game::scene::MenuScene(_graphic, _timer)));
    _scenes.emplace(std::pair(1, new rtype::game::scene::GameScene(_graphic, _timer)));
    _graphic->init();
}

void rtype::game::Game::start()
{
    _actual_scene = _scenes.find(0)->second;
    _actual_scene->loadScene();
    loop();
}

void rtype::game::Game::changeScene(size_t const &id)
{
    _actual_scene->unloadScene();
    _actual_scene = _scenes.find(id)->second;
    _actual_scene->loadScene();
}

void rtype::game::Game::loop()
{
    while (_graphic->isWindowOpen()) {
        switch (_actual_scene->displayScene()) {
        case engine::scene::MENU: changeScene(0); break;
        case engine::scene::GAME: changeScene(1); break;
        case engine::scene::QUIT: return;
        default: break;
        }
    }
}

void rtype::game::Game::stop()
{
    for (auto &scene : _scenes) {
        scene.second->unloadScene();
    }
}
