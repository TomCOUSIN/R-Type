/*
** EPITECH PROJECT, 2022
** CPP_rtype_2019
** File description:
** Created by tomcousin,
*/

#ifndef CPP_RTYPE_2019_PARALLAXENTITY_HPP
#define CPP_RTYPE_2019_PARALLAXENTITY_HPP

#include <memory>
#include <iostream>
#include <functional>
#include "EntityCreator.hpp"
#include "Position.hpp"
#include "Sprite.hpp"
#include "Speed.hpp"

namespace rtype::sfml::entity {

    class ParallaxEntity : public engine::entity::EntityCreator {

        public:
        /**
         * @brief Construct a Parallax Entity
         */
        ParallaxEntity(engine::GameEngine &game_engine
        , std::string const &background_path
        , std::string const &foreground_path
        , float const &background_speed_x);

        /**
         * @brief Destroy all parallax Entity
         */
        void destroyParallax();

        /**
         * @brief Get the background Entity
         *
         * @return The background Entity
         */
        engine::entity::Entity getBackgroundEntity() const;

        /**
		 * @brief The type of the Created Entity
		 */
        static const engine::entity::EntityType type;

        private:
        /**
         * @brief The background Entity
         */
        engine::entity::Entity _background_entity;

        /**
         * @brief The foreground Entity
         */
        engine::entity::Entity _foreground_entity;

        /**
         * @brief The background position
         */
        std::shared_ptr<engine::component::Position> _background_position;

        /**
         * @brief The foreground position
         */
        std::shared_ptr<engine::component::Position> _foreground_position;

        /**
         * @nrief The background speed
         */
        std::shared_ptr<engine::component::Speed> _background_speed;

        /**
         * @nrief The foreground speed
         */
        std::shared_ptr<engine::component::Speed> _foreground_speed;

        /**
         * @nrief The background sprite
         */
        std::shared_ptr<component::Sprite> _background_sprite;

        /**
         * @nrief The foreground sprite
         */
        std::shared_ptr<component::Sprite> _foreground_sprite;
    };
}

#endif //CPP_RTYPE_2019_PARALLAXENTITY_HPP
