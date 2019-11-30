/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "MenuScene.hpp"

rtype::game::scene::MenuScene::MenuScene(std::shared_ptr<graphic::IGraphic> graphic) :
_graphic(graphic) {}

void rtype::game::scene::MenuScene::loadScene()
{
    _entities.emplace(std::pair("title", _graphic->createText("Title")));
    _graphic->setPosition(_entities["title"], 50.0f, 50.0f);
    _graphic->setVisible(_entities["title"], true);
}

void rtype::game::scene::MenuScene::displayScene(float const &delta)
{
    _graphic->update(delta);
}

void rtype::game::scene::MenuScene::unloadScene()
{
    _graphic->removeElement(_entities["title"]);
}
