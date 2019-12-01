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

		/**
		 * @brief Get the Entity of the Button
		 * @return
		 */
		engine::entity::Entity getButtonEntity() const;

		/**
		 * @brief Destroy the Entity inside of the GameEngine
		 */
		void destroyEntityButton();

	// @MARK Listeners
		public:
		/**
		 * @brief listener on mouse pressed
		 *
		 * @param event mouse event
		 */
		void onMousePressed(engine::event::Event const &event);

		/**
		 * @brief listener on mouse released
		 *
		 * @param event mouse event
		 */
		void onMouseReleased(engine::event::Event const &event);

		/**
		 * @brief listener on mouse begin collide with the button
		 *
		 * @param event mouse event
		 */
		void onMouseCollide(engine::event::Event const &event);

		/**
		 * @brief listener on mouse end collide with the button
		 *
		 * @param event mouse event
		 */
		void onMouseEndCollide(engine::event::Event const &event);

    // @MARK Static
		public:
		/**
		 * @brief The type of the Created Entity
		 */
		static const engine::entity::EntityType type;

	// @MARK Properties
		private:
	    engine::entity::Entity _button_entity;
	    engine::entity::Entity _text_entity;
		std::function<void(void)> _callback;
		std::shared_ptr<engine::component::Position> _position;
		std::shared_ptr<sfml::component::Button> _button;
		std::shared_ptr<sfml::component::Text> _text;
	};

}

#endif /* !BUTTONENTITY_HPP_ */
