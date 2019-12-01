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
    _entities.emplace("parallax", _graphic->createParallax("./assets/parallax/Background.jpg", "./assets/parallax/Foreground.png", 2));
    _entities.emplace("sprite", _graphic->createSprite("./assets/spaceship.gif", 300, 300, 33, 17, 3, 3, 1, true, 10, 10));
}

rtype::engine::scene::SCENE rtype::game::scene::GameScene::displayScene()
{
    _timer->start();
    while (_graphic->isWindowOpen() && !_end) {
        if (_timer->getElapsedTime() >= 0.005f) {
            _graphic->update(_timer->getElapsedTime());
            _timer->restart();
        }
    }
    return rtype::engine::scene::MENU;
}

void rtype::game::scene::GameScene::unloadScene()
{
    _graphic->removeElement(_entities["sprite"]);
    _graphic->removeElement(_entities["parallax"]);
    _entities.clear();
}
