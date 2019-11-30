/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_TEXT_HPP
#define CPP_RTYPE_2019_TEXT_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Component.hpp"

namespace rtype::sfml::component {

    /**
     * @brief Text Component to draw Text
     */
    struct Text : public engine::component::Component {

        explicit Text(std::string const &message) {
            font.loadFromFile("./assets/fonts/Roboto-Condensed.ttf");
            text.setFont(font);
            text.setString(message);
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::White);
            auto textRect = text.getLocalBounds();
            text.setOrigin(textRect.width/2, textRect.height/2);
        }

        void update(std::string const &message) {
            text.setString(message);
        }

        /**
         * @brief The text to use
         */
        sf::Text text;

        /**
         * @brief The font of the text
         */
        sf::Font font;

        /**
         * @brief The type of the Component Text
         */
        static const engine::component::ComponentType type = 5;
    };
}

#endif //CPP_RTYPE_2019_TEXT_HPP
