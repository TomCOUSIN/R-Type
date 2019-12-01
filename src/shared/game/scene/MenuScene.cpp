/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <iostream>
#include "MenuScene.hpp"

rtype::game::scene::MenuScene::MenuScene(std::shared_ptr<graphic::IGraphic> graphic, std::shared_ptr<timer::ITimer> timer) :
_end(false), _timer(timer), _graphic(graphic) {}

void rtype::game::scene::MenuScene::loadScene()
{
    _entities.emplace(std::pair("title", _graphic->createText("Title", 50)));
    _graphic->setPosition(_entities["title"], 50.0f, 50.0f);
    _graphic->setVisible(_entities["title"], true);
    _entities.emplace(std::pair("button", _graphic->createButton("Game", 300, 300, 200, 100, [this]{_end = true;})));
}

rtype::engine::scene::SCENE rtype::game::scene::MenuScene::displayScene()
{
    _timer->start();
    while (_graphic->isWindowOpen() && !_end) {
        if (_timer->getElapsedTime() >= 0.005f) {
            _graphic->update(_timer->getElapsedTime());
            _timer->restart();
        }
    }
    _end = false;
    return rtype::engine::scene::GAME;
}

void rtype::game::scene::MenuScene::unloadScene()
{
    _graphic->removeElement(_entities["title"]);
    _graphic->removeElement(_entities["button"]);
    _entities.clear();
}
