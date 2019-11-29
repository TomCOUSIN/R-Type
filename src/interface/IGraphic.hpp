/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_IGRAPHIC_HPP
#define CPP_RTYPE_2019_IGRAPHIC_HPP

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
        virtual void isWindowOpen() = 0;

        /**
         * @brief Initialize the mandatory part of the Graphic Library
         */
        virtual void init() = 0;

        /**
         * @brief Update the entity of the Graphic Library
         */
        virtual void update() = 0;

        /**
         * @brief Create a Button
         */
        virtual void createButton() = 0;

        /**
         * @brief Create a Text
         */
        virtual void createText() = 0;

        /**
         * @brief Create a Sprite
         */
        virtual void createSprite() = 0;
    };
}

#endif //CPP_RTYPE_2019_IGRAPHIC_HPP
