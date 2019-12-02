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

    namespace sfml {

        namespace component {

            /**
             * @brief A Sprite Component
             */
            struct Sprite : public engine::component::Component {

                /**
                 * @brief Construct a new Sprite Component
                 *
                 * @param texture_path The path to the texture
                 * @param width The width of the Sprite
                 * @param height The height of the Sprite
                 * @param scale_width The width scale of the Sprite
                 * @param scale_height The height scale of the Sprite
                 * @param sprite_count The number of sprite in the spritesheet
                 */
                explicit Sprite(std::string const &texture_path,
                    float const &width,
                    float const &height,
                    float const &scale_width = 1.0f,
                    float const &scale_height = 1.0f,
                    size_t const &sprite_count = 1.0f,
                    engine::component::CENTERED centered = engine::component::NONE) :
                size(width, height), scale(scale_width, scale_height), sprite_count(sprite_count), actual_sprite(0)
                {
                    if (texture.loadFromFile(texture_path)) {
                        sprite.setTexture(texture);
                        sprite.setScale(scale);
                        sprite.setOrigin(centered & engine::component::CENTERED::X ? width/2 : 0
                                        , centered & engine::component::CENTERED::Y ? height/2 : 0);
                        sprite.setTextureRect(sf::IntRect(0, 0, width, height));
                    }
                }

                /**
                 * @brief Update to the next sprite if the Sprite is a spritesheet
                 */
                void next() {
                    ++actual_sprite;
                    if (sprite_count == actual_sprite) {
                        actual_sprite = 0;
                    }
                    sprite.setTextureRect(sf::IntRect(size.x * actual_sprite, 0, size.x, size.y));
                }

                /**
                 * @brief The vector containing the scale of the sprite
                 */
                sf::Vector2f scale;

                /**
                 * @brief The vector containing the size of the sprite
                 */
                sf::Vector2f size;

                /**
                 * @brief The total count of the different Sprite
                 */
                size_t sprite_count;

                /**
                 * @brief The actual count of the Sprite
                 */
                size_t actual_sprite;

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
                static const engine::component::ComponentType type = 1 << engine::component::COMPONENT_TYPE::SPRITE;
            };
        }
    }
}

#endif //CPP_RTYPE_2019_SPRITE_HPP
