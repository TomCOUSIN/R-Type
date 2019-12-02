/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by lucasmrdt
*/

#include <criterion/criterion.h>
#include <vector>

#include "BoostNetwork.hpp"

using namespace rtype::network;

Test(boost_tests, test_boost_udp)
{
    BoostNetwork network;
    std::size_t port = 8084;
    const std::string payload = "test";
    Packet data(0, payload);

    network.createUDPEndpoint(port, [=](Packet &packet) {
        std::string received_payload;
        packet >> received_payload;
        cr_assert_str_eq(received_payload.data(), payload.data());
    });
    network.sendUDPData(data, "127.0.0.1", port);
    network.sendUDPData(data, "127.0.0.1", port);
}
