/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include <thread>
#include <functional>

#include "GameScene.hpp"
#include "InputEvent.hpp"
#include "Position.hpp"

namespace rtype::client::scene {

GameScene::GameScene(engine::GameEngine &engine
                    , graphic::IGraphic &graphic
                    , audio::IAudio &audio
                    , client::ClientNetwork &network
                    , std::size_t framerate)
    : _engine(engine)
    , _graphic(graphic)
    , _audio(audio)
    , _network(network)
    , _framerate(framerate)
{
}

void GameScene::loadScene()
{
    auto on_input = [this](engine::event::Event const &event) { _network.sendInput(event.getEventType()); };
    auto on_mouse = [this](engine::event::Event const &event) { _network.sendMouse(*event.getEventData<engine::component::Position>()); };
    auto on_fire = [this](engine::event::Event const &event) { _network.sendFire(*event.getEventData<engine::component::Position>()); };
    _engine.subscribeTo(engine::event::Event(engine::event::EVENT_SENDER::INPUT, game::event::ARROW_DOWN), on_input);
    _engine.subscribeTo(engine::event::Event(engine::event::EVENT_SENDER::INPUT, game::event::ARROW_UP), on_input);
    _engine.subscribeTo(engine::event::Event(engine::event::EVENT_SENDER::INPUT, game::event::ARROW_RIGHT), on_input);
    _engine.subscribeTo(engine::event::Event(engine::event::EVENT_SENDER::INPUT, game::event::ARROW_LEFT), on_input);
    _engine.subscribeTo(engine::event::Event(engine::event::EVENT_SENDER::INPUT, game::event::MOUSE_MOUVED), on_mouse);

    _network.subscribeTo(game::network::CREATE_PLAYER, std::bind(&GameScene::onCreatePlayer, this, std::placeholders::_1));
    _network.subscribeTo(game::network::MOVE_PLAYER, std::bind(&GameScene::onMovePlayer, this, std::placeholders::_1));
    _network.subscribeTo(game::network::CREATE_BULLET, std::bind(&GameScene::onBulletFired, this, std::placeholders::_1));

    _engine.subscribeTo(engine::event::Event(engine::event::EVENT_SENDER::FIRE, game::event::FireEventType::ALLY), on_fire);

    _entities.emplace(std::pair("level", _audio.createMusic("./assets/sounds/level1.ogg")));
    _entities.emplace("parallax", _graphic.createParallax("./assets/parallax/Background.jpg", "./assets/parallax/Foreground.png", 2));
    _entities.emplace("shot_sound", _audio.createSound("./assets/sounds/shot.wav", rtype::sfml::event::InputEvent::InputEventType::SPACE));
    _audio.play(_entities["level"]);
    _network.startGame();
}

rtype::engine::scene::SCENE GameScene::displayScene()
{
    while (_graphic.isWindowOpen()) {
        _graphic.update(_framerate);
        std::this_thread::sleep_for(std::chrono::milliseconds(_framerate));
    }
    return rtype::engine::scene::MENU;
}

void GameScene::unloadScene()
{
    _audio.stop(_entities["level"]);
    for (auto &entity : _entities) {
        _graphic.removeElement(entity.second);
    }
    _entities.clear();
}

void GameScene::onMovePlayer(rtype::network::Packet &packet)
{
    static auto &position_store = _engine.getComponentStorage<engine::component::Position>();

    auto target_position = packet.getPayload<engine::component::Position>();
    auto user = packet.getPayload<std::string>();
    auto entity = _entities.find(user);
    if (entity == _entities.end()) {
        std::cerr << "can't found entity " << user << std::endl;
        return;
    }
    auto position = position_store.getComponent<engine::component::Position>(entity->second);
    position->x = target_position.x;
    position->y = target_position.y;
}

void GameScene::onCreatePlayer(rtype::network::Packet &packet)
{
    auto position = packet.getPayload<engine::component::Position>();
    auto remote_entity = packet.getPayload<std::string>();
    auto sprite = _graphic.createSprite("./assets/spaceship.gif", position.x, position.y, 33, 17, 3, 3, 1, false, 10, 10, true);
    _entities.emplace(remote_entity, sprite);
}

void GameScene::onBulletFired(rtype::network::Packet &packet)
{
    auto position = packet.getPayload<engine::component::Position>();
    auto remote_entity = packet.getPayload<std::string>();
    auto sprite = _graphic.createBullet(_engine, "./assets/bullet.gif", position.x, position.y, 32, 12, 3, 3, 3, 1);
    _entities.emplace(remote_entity, sprite);
}

}
