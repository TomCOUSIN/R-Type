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
                 * @param width The width of the Button
                 * @param height The height of the Button
                 */
                Button(float const &width, float const &height) :
                size(width, height), shape(size), hasBeenClicked(false) {
                    shape.setOrigin(width/2, height/2);
                    shape.setFillColor(sf::Color::Black);
                    shape.setOutlineThickness(3);
                    shape.setOutlineColor(sf::Color::White);
                }

                /**
                 * @brief The size of the Button
                 */
                sf::Vector2f size;

                /**
                 * @brief The shape of the Button
                 */
                sf::RectangleShape shape;

                /**
                 * @brief Boolean to know if a button has been clicked
                 */
                bool hasBeenClicked;

                /**
                 * @brief When the mouse isn't on the Button
                 */
                void onDisplay() {
                    hasBeenClicked = false;
                    shape.setFillColor(sf::Color::Black);
                }

                /**
                 * @brief When the mouse is on the Button
                 */
                void onHover() {
                    hasBeenClicked = false;
                    shape.setFillColor(sf::Color::White);
                }

                /**
                 * @brief When the mouse click on the Button
                 */
                void onClick() {
                    hasBeenClicked = true;
                }

                /**
                 * @brief The type of the Component Button
                 */
                static const engine::component::ComponentType type = 4;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_BUTTON_HPP
