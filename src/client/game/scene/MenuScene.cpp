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
}

rtype::engine::scene::SCENE rtype::game::scene::MenuScene::displayScene()
{
    _timer->start();
    while (_timer->getElapsedTime() <= 5.0f) {
        _graphic->update(0.1f);
    }
    return rtype::engine::scene::GAME;
}

void rtype::game::scene::MenuScene::unloadScene()
{
    _graphic->removeElement(_entities["title"]);
    _graphic->removeElement(_entities["button"]);
}
