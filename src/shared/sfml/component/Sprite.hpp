/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SPRITE_HPP
#define CPP_RTYPE_2019_SPRITE_HPP

#include <SFML/Graphics.hpp>
#include "Component.hpp"

namespace rtype {

    namespace engine {

        namespace component {

            /**
             * @brief A Sprite Component
             */
            struct Sprite : public Component {

                /**
                 * @brief Construct a new Sprite Component
                 *
                 * @param texture_path The path to the texture
                 */
                explicit Sprite(std::string const &texture_path) {
                    if (texture.loadFromFile(texture_path))
                        sprite.setTexture(texture);
                }

                /**
                 * @brief The Texture of the Component
                 */
                sf::Texture texture;

                /**
                 * @brief The Sprite of the Component
                 */
                sf::Sprite sprite;

                /**
                 * @brief The type of the Component Position
                 */
                static const ComponentType type = 2;
            };
        }
    }
}
#endif //CPP_RTYPE_2019_SPRITE_HPP
