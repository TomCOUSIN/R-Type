/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_BUTTON_HPP
#define CPP_RTYPE_2019_BUTTON_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Component.hpp"

namespace rtype {

    namespace sfml {

        namespace component {

            /**
             * @brief a Button Component
             */
            struct Button : public engine::component::Component {

                /**
                 * @brief Construct a Button Component
                 *
                 * @param text The Text of the Button
                 * @param width The width of the Button
                 * @param height The height of the Button
                 */
                Button(std::string const &text, float const &width, float const &height) :
                text(text), size(width, height), shape(size) {
                    shape.setFillColor(sf::Color::Black);
                    shape.setOutlineThickness(3);
                    shape.setOutlineColor(sf::Color::White);
                }

                /**
                 * @brief The text of the Button
                 */
                std::string text;

                /**
                 * @brief The size of the Button
                 */
                sf::Vector2f size;

                /**
                 * @brief The shape of the Button
                 */
                sf::RectangleShape shape;

                /**
                 * @brief When the mouse isn't on the Button
                 */
                void onDisplay() {
                    shape.setFillColor(sf::Color::Black);
                }

                /**
                 * @brief When the mouse is on the Button
                 */
                void onHover() {
                    shape.setFillColor(sf::Color::White);
                }

                /**
                 * @brief When the mouse click on the Button
                 */
                void onClick() {
                    shape.setFillColor(sf::Color::Red);
                }

            };
        }
    }
}

#endif //CPP_RTYPE_2019_BUTTON_HPP
