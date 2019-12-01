/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "GameScene.hpp"


rtype::game::scene::GameScene::GameScene(std::shared_ptr<graphic::IGraphic> graphic, std::shared_ptr<timer::ITimer> timer) :
_end(false), _timer(timer), _graphic(graphic) {}

void rtype::game::scene::GameScene::loadScene()
{
    _entities.emplace("player", _graphic->createSprite("./assets/flappy.png", 17, 20, 3, 3, 12));
    _graphic->setPosition(_entities["player"], 50.0f, 50.0f);
    _graphic->setVisible(_entities["player"], true);
}

rtype::engine::scene::SCENE rtype::game::scene::GameScene::displayScene()
{
    _timer->start();
    while (_graphic->isWindowOpen() && !_end) {
        if (_timer->getElapsedTime() >= 0.1f) {
            _graphic->update(_timer->getElapsedTime());
            _timer->restart();
        }
    }
    return rtype::engine::scene::MENU;
}

void rtype::game::scene::GameScene::unloadScene()
{
    _graphic->removeElement(_entities["player"]);
    _entities.clear();
}
