/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <iostream>
#include "MenuScene.hpp"

rtype::game::scene::MenuScene::MenuScene(std::shared_ptr<graphic::IGraphic> graphic, std::shared_ptr<timer::ITimer> timer) :
_timer(timer), _graphic(graphic) {}

void rtype::game::scene::MenuScene::loadScene()
{
    _quit = false;
    _play = false;
    _entities.emplace(std::pair("title", _graphic->createText("R-Type", 50)));
    _graphic->setPosition(_entities["title"], 960.0f, 100.0f);
    _graphic->setVisible(_entities["title"], true);
    _entities.emplace(std::pair("play", _graphic->createButton("Play", 960, 400, 200, 100, [this]{_play = true;})));
    _entities.emplace(std::pair("quit", _graphic->createButton("Quit", 960, 600, 200, 100, [this]{_quit = true;})));
}

rtype::engine::scene::SCENE rtype::game::scene::MenuScene::displayScene()
{
    _timer->start();
    while (_graphic->isWindowOpen() && !_play && !_quit) {
        if (_timer->getElapsedTime() >= 0.005f) {
            _graphic->update(_timer->getElapsedTime());
            _timer->restart();
        }
    }
    return _play ? rtype::engine::scene::GAME : rtype::engine::scene::QUIT;
}

void rtype::game::scene::MenuScene::unloadScene()
{
    _graphic->removeElement(_entities["title"]);
    _graphic->removeElement(_entities["play"]);
    _graphic->removeElement(_entities["quit"]);
    _entities.clear();
}
