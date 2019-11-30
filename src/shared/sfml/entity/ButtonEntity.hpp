/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef BUTTONENTITY_HPP_
#define BUTTONENTITY_HPP_

#include <functional>

#include "EntityCreator.hpp"
#include "Position.hpp"

namespace rtype::sfml::entity {

	class ButtonEntity : public engine::entity::EntityCreator {

	// @MARK Constructors/Destructors
		public:
			/**
			 * @brief Construct a new Button Entity
			 */
			ButtonEntity(engine::GameEngine &game_engine
                          , std::string const &title
                          , float const &x
                          , float const &y
                          , float const &width
                          , float const &height
                          , std::function<void(void)> callback);

	// @MARK Properties
		private:
			std::shared_ptr<engine::component::Position> _position;
	};

}

#endif /* !BUTTONENTITY_HPP_ */
