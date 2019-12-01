/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_SFMLGRAPHIC_HPP
#define CPP_RTYPE_2019_SFMLGRAPHIC_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "ParallaxEntity.hpp"
#include "SpriteEntity.hpp"
#include "ButtonEntity.hpp"
#include "MouseEntity.hpp"
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
        engine::entity::Entity createButton(std::string const &title
            , float const &x
            , float const &y
            , float const &width
            , float const &height
            , std::function<void(void)> callback) final;

        /**
         * @brief Create a Parallax
         */
        engine::entity::Entity createParallax(std::string const &background_path
            , std::string const &foreground_path
            , float const &background_speed_x) final;

        /**
         * @brief Create a Text
         */
        engine::entity::Entity createText(std::string const &message, size_t const &size) final;

        /**
         * @brief Create a Sprite
         */
        engine::entity::Entity createSprite(std::string const &texture_path
            , float const &x
            , float const &y
            , float const &width
            , float const &height
            , float const &scale_width
            , float const &scale_height
            , size_t const &sprite_count
            , bool const &movable
            , float const &speed_x
            , float const &speed_y
            , bool const &can_fire) final;

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
         * @brief Remove an element
         *
         * @param entity the Entity of the element to remove
         */
        void removeElement(engine::entity::Entity const &entity) final;

        /**
         * @brief Check if a Button as been clicked
         *
         * @param entity the Entity linked with the Button
         * @return true on success
         * @return false on failure
         */
        bool isButtonClicked(engine::entity::Entity const &entity) final;

        private:
        /**
         * @brief The MouseEntity to handle mouse gesture
         */
        rtype::sfml::entity::MouseEntity _mouse;

        /**
         * @bried The Button to use
         */
        std::vector<std::shared_ptr<rtype::sfml::entity::ButtonEntity>> _buttons;

        /**
         * @bried The Parallax to use
         */
        std::vector<std::shared_ptr<rtype::sfml::entity::ParallaxEntity>> _parallax;

        /**
         * @brief The Sprite to use
         */
        std::vector<std::shared_ptr<rtype::sfml::entity::SpriteEntity>> _sprites;

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
