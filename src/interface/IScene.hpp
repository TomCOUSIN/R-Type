/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_ISCENE_HPP
#define CPP_RTYPE_2019_ISCENE_HPP

namespace rtype::engine::scene {

    /**
     * @brief Interface IScene to handle scene managed by the GameEngine
     */
    class IScene {

        public:
        /**
         * @brief Destroy an IScene object
         */
        virtual ~IScene() = default;

        /**
         *  @brief The Scene loads everything needed for it to run properly
         */
        virtual void loadScene() = 0;

        /**
         *  @brief Display the scene by using the engine
         */
        virtual void displayScene() = 0;

        /**
         *  @brief Unload the scene by removing entity, Component and ISystem in the GameEngine
         */
        virtual void unloadScene() = 0;
    };
}

#endif //CPP_RTYPE_2019_ISCENE_HPP
