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

        explicit Text(std::string const &message, size_t const &size, engine::component::CENTERED centered = engine::component::ALL)
            : centered(centered)
        {
            font.loadFromFile("./assets/fonts/Roboto-Condensed.ttf");
            text.setFont(font);
            text.setString(message);
            text.setCharacterSize(size);
            text.setFillColor(sf::Color::White);
            auto textRect = text.getLocalBounds();
            text.setOrigin(centered & engine::component::CENTERED::X ? textRect.width/2 : 0
                          , centered & engine::component::CENTERED::Y ? textRect.height/2 : 0);
        }

        void update(std::string const &message) {
            text.setString(message);
            auto textRect = text.getLocalBounds();
            text.setOrigin(centered & engine::component::CENTERED::X ? textRect.width/2 : 0
                          , centered & engine::component::CENTERED::Y ? textRect.height/2 : 0);
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
         * @brief The font centered state
         */
        engine::component::CENTERED centered;

        /**
         * @brief The type of the Component Text
         */
        static const engine::component::ComponentType type = 1 << engine::component::COMPONENT_TYPE::TEXT;
    };
}

#endif //CPP_RTYPE_2019_TEXT_HPP
