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
    _entities.emplace(std::pair("title", _graphic->createText("Title")));
    _graphic->setPosition(_entities["title"], 50.0f, 50.0f);
    _graphic->setVisible(_entities["title"], true);
    _entities.emplace(std::pair("button", _graphic->createButton(100, 100)));
    _graphic->setPosition(_entities["button"], 200.0f, 200.0f);
    _graphic->setVisible(_entities["button"], true);
}

rtype::engine::scene::SCENE rtype::game::scene::MenuScene::displayScene()
{
    _timer->start();
    while (_graphic->isWindowOpen() && !_graphic->isButtonClicked(_entities["button"])) {
        if (_timer->getElapsedTime() >= 0.1f) {
            _graphic->update(_timer->getElapsedTime());
            _timer->restart();
        }
    }
    return rtype::engine::scene::GAME;
}

void rtype::game::scene::MenuScene::unloadScene()
{
    _graphic->removeElement(_entities["title"]);
    _graphic->removeElement(_entities["button"]);
    _entities.clear();
}
