/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#include "SfmlTimer.hpp"

void rtype::sfml::timer::SfmlTimer::start()
{
    _clock.restart();
}

void rtype::sfml::timer::SfmlTimer::restart()
{
    _clock.restart();
}

float rtype::sfml::timer::SfmlTimer::getElapsedTime()
{
    return _clock.getElapsedTime().asSeconds();
}

void rtype::sfml::timer::SfmlTimer::stop()
{}
