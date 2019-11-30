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
#include "Button.hpp"
#include "Text.hpp"

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

    // @MARK Static
		public:
		/**
		 * @brief The type of the Created Entity
		 */
		static const engine::entity::EntityType type;

	// @MARK Properties
		private:
		std::function<void(void)> _callback;
		std::shared_ptr<engine::component::Position> _position;
		std::shared_ptr<sfml::component::Button> _button;
		std::shared_ptr<sfml::component::Text> _text;
	};

}

#endif /* !BUTTONENTITY_HPP_ */
