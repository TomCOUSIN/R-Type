/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef GAME_HPP_
#define GAME_HPP_

namespace rtype::game {

    namespace network {
        enum PACKET_TYPE {
            CONNECT,
            DISCONNECT,
            CREATE_SESSION,
            JOIN_SESSION,
            INPUT,
            MOUSE,
            CREATE_PLAYER,
            MOVE_PLAYER,
            START_GAME,
        };
    }

    namespace event {
        enum InputEventType {
            ARROW_UP,
            ARROW_DOWN,
            ARROW_RIGHT,
            ARROW_LEFT,
            MOUSE_MOUVED,
            LastInputEventType
        };
    }

}

#endif /* !GAME_HPP_ */
