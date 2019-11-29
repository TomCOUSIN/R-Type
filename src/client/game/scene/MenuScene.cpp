/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "MenuScene.hpp"

rtype::game::MenuScene::MenuScene(rtype::engine::GameEngine &engine,
    std::shared_ptr<graphic::IGraphic> graphic,
    std::shared_ptr<timer::ITimer> timer) :
_engine(engine), _graphic(graphic), _timer(timer) {}

void rtype::game::MenuScene::loadScene()
{
    _entities.emplace(std::pair("title", _graphic->createText("Title")));
    _graphic->setPosition(_entities["title"], 50.0f, 50.0f);
    _graphic->setVisible(_entities["title"], true);
}

void rtype::game::MenuScene::displayScene()
{
    _timer->start();
    while (_graphic->isWindowOpen()) {
        if (_timer->getElapsedTime() >= 0.1f) {
            _graphic->update(_timer->getElapsedTime());
            _timer->restart();
        }
    }
}

void rtype::game::MenuScene::unloadScene()
{}
