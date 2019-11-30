/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_IGRAPHIC_HPP
#define CPP_RTYPE_2019_IGRAPHIC_HPP

#include <iostream>
#include "Entity.hpp"

namespace rtype::graphic {

    /**
     * @brief Interface for all Graphic library
     */
    class IGraphic {

        public:
        /**
         * @brief Destroy an IGraphic object
         */
        virtual ~IGraphic() = default;

        /**
         * @brief Check if the window is open
         */
        virtual bool isWindowOpen() = 0;

        /**
         * @brief Initialize the mandatory part of the Graphic Library
         */
        virtual void init() = 0;

        /**
         * @brief Update the entity of the Graphic Library
         */
        virtual void update(float const &delta) = 0;

        /**
         * @brief Create a Button
         */
        virtual engine::entity::Entity createButton(float const &width, float const &height) = 0;

        /**
         * @brief Create a Text
         */
        virtual engine::entity::Entity createText(std::string const &message) = 0;

        /**
         * @brief Create a Sprite
         */
        virtual engine::entity::Entity createSprite(std::string const &texture_path,
            float const &width,
            float const &height,
            float const &scale_width,
            float const &scale_height,
            size_t const &sprite_count) = 0;

        /**
         * @brief The the position of a Component
         */
        virtual void setPosition(engine::entity::Entity const &entity, float const &x_position, float const &y_position) = 0;

        /**
         *  @brief Set if an entity is visible or not
         *
         *  @param entity The Entity to use
         *  @param visible The boolean to set visible to true or false
         */
        virtual void setVisible(engine::entity::Entity const &entity, bool visible) = 0;

        /**
         *  @brief Set a Component to be movable using event
         *
         *  @param entity The Entity to use
         *  @param x_speed The x value of the Speed
         *  @param y_speed The y value of the Speed
         */
        virtual void setMovable(engine::entity::Entity const &entity, float const &x_speed, float const &y_value) = 0;

        /**
         * @brief Remove an element
         *
         * @param entity the Entity of the element to remove
         */
        virtual void removeElement(engine::entity::Entity const &entity) = 0;

        /**
         * @brief Check if a Button as been clicked
         *
         * @param entity the Entity linked with the Button
         */
        virtual bool isButtonClicked(engine::entity::Entity const &entity) = 0;
    };
}

#endif //CPP_RTYPE_2019_IGRAPHIC_HPP