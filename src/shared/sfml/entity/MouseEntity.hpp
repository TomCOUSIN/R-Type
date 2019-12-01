/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef MOUSEENTITY_HPP_
#define MOUSEENTITY_HPP_

#include <functional>

#include "EntityCreator.hpp"
#include "Position.hpp"

namespace rtype::sfml::entity {

	class MouseEntity : public engine::entity::EntityCreator {

	// @MARK Constructors/Destructors
		public:
		/**
		 * @brief Construct a new Mouse Entity
		 */
		MouseEntity(engine::GameEngine &game_engine);

	// @MARK Listeners
		public:
		/**
		 * @brief Listener on mouse moved
		 * @param event the dispatched event
		 */
		void onMouseMove(engine::event::Event const &event);

    // @MARK Static
		public:
		/**
		 * @brief The type of the Created Entity
		 */
		static const engine::entity::EntityType type;

	// @MARK Properties
		private:
		bool _clicked;
		std::shared_ptr<engine::component::Position> _position;
	};

}

#endif /* !MOUSEENTITY_HPP_ */
