/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by lucasmrdt
*/

#include <criterion/criterion.h>
#include <vector>

#include "Packet.hpp"

using namespace rtype::network;

Test(packet_tests, test_packet_basic_item_insertion)
{
    Packet packet;
    int nb = 0;

    packet << 1;
    packet << 2;
    packet << 3;
    packet >> nb;
    cr_assert_eq(nb, 1);
    packet >> nb;
    cr_assert_eq(nb, 2);
    packet >> nb;
    cr_assert_eq(nb, 3);
}

Test(packet_tests, test_packet_advenced_item_insertion)
{
    Packet packet;
    std::vector list = {1, 2, 3, 4};
    std::vector<int> list2;

    packet << list;
    packet >> list2;
    cr_assert_eq(list.size(), list2.size());
    for (std::size_t i = 0; i < list.size(); ++i) {
        cr_assert_eq(list[i], list2[i]);
    }
}
Test(packet_tests, test_packet_creation)
{
    std::string label = "test";
    Packet packet(0, label);
    std::string test;

    packet >> test;
    cr_assert_str_eq(test.data(), label.data());
}
