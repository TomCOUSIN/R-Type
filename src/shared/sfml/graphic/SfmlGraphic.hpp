/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SFMLGRAPHIC_HPP
#define CPP_RTYPE_2019_SFMLGRAPHIC_HPP

#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"
#include "IGraphic.hpp"

namespace rtype::sfml::graphic {

    /**
     * @brief Sfml Graphic Library
     */
    class SfmlGraphic : public rtype::graphic::IGraphic {

        public:
        /**
         * @breif Construct a SfmlGraphic object
         * @param engine
         */
        SfmlGraphic(engine::GameEngine &engine);

        /**
         * @brief Destroy a SfmlGraphic object
         */
        ~SfmlGraphic() final = default;

        /**
         * @brief Check if the window is open
         */
        bool isWindowOpen() final;

        /**
         * @brief Initialize the mandatory part of the Graphic Library
         */
        void init() final;

        /**
         * @brief Update the entity of the Graphic Library
         */
        void update(float const &delta) final;

        /**
         * @brief Create a Button
         */
        engine::entity::Entity createButton(float const &width, float const &height, void (*fptr)(void)) final;

        /**
         * @brief Create a Text
         */
        engine::entity::Entity createText(std::string const &message) final;

        /**
         * @brief Create a Sprite
         */
        engine::entity::Entity createSprite(std::string const &texture_path,
            float const &width,
            float const &height,
            float const &scale_width,
            float const &scale_height,
            size_t const &sprite_count) final;

        /**
         * @brief The the position of a Component
         */
        void setPosition(engine::entity::Entity const &entity, float const &x_position, float const &y_position) final;

        /**
         *  @brief Set if an entity is visible or not
         *
         *  @param entity The Entity to use
         *  @param visible The boolean to set visible to true or false
         */
        void setVisible(engine::entity::Entity const &entity, bool visible) final;

        /**
         *  @brief Set a Component to be movable using event
         *
         *  @param entity The Entity to use
         *  @param x_speed The x value of the Speed
         *  @param y_speed The y value of the Speed
         */
        void setMovable(engine::entity::Entity const &entity, float const &x_speed, float const &y_value) final;

        private:
        /**
         * @brief the GameEngine used to load Component, System and entity
         */
        engine::GameEngine &_engine;

        /**
         * @brief The window used to display the program
         */
        sf::RenderWindow _window;
    };
}

#endif //CPP_RTYPE_2019_SFMLGRAPHIC_HPP
