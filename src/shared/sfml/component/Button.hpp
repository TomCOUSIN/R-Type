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
                Button(float const &width, float const &height, engine::component::CENTERED centered = engine::component::ALL) :
                size(width, height), shape(size), clicked(false), hover(false) {
                    shape.setOrigin(centered & engine::component::CENTERED::X ? width/2 : 0
                                   , centered & engine::component::CENTERED::Y ? height/2 : 0);
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
                bool clicked;


                /**
                 * @brief Boolean to know if a button has been clicked
                 */
                bool hover;

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

                /**
                 * @brief The type of the Component Button
                 */
                static const engine::component::ComponentType type = 1 << engine::component::COMPONENT_TYPE::BUTTON;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_BUTTON_HPP
