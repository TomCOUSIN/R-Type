/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** created by lucasmrdt
*/

#ifndef INPUTENTITY_HPP_
#define INPUTENTITY_HPP_

#include <functional>

#include "EntityCreator.hpp"
#include "Position.hpp"
#include "Button.hpp"
#include "Text.hpp"

namespace rtype::sfml::entity {

	class InputEntity : public engine::entity::EntityCreator {

	// @MARK Constructors/Destructors
		public:
		/**
		 * @brief Construct a new Input Entity
		 */
		InputEntity(engine::GameEngine &game_engine
						, std::string const &title
						, float const &x
						, float const &y
						, float const &width
						, float const &height
						, std::function<void(std::string)> on_submit
						, std::size_t max_chars = 15);

		/**
		 * @brief Get the Entity of the Input
		 * @return
		 */
		engine::entity::Entity getInputEntity() const;

		/**
		 * @brief Destroy the Entity inside of the GameEngine
		 */
		void destroyEntityInput();

	// @MARK Listeners
		public:
		/**
		 * @brief listener on mouse pressed
		 *
		 * @param event mouse event
		 */
		void onMousePressed(engine::event::Event const &event);

		/**
		 * @brief listener on text entered
		 *
		 * @param event mouse event
		 */
		void onTextEntered(engine::event::Event const &event);

		/**
		 * @brief listener on backspace key pressed
		 *
		 * @param event mouse event
		 */
		void onBackspace(engine::event::Event const &event);

		/**
		 * @brief listener on backspace key pressed
		 *
		 * @param event mouse event
		 */
		void onSubmit(engine::event::Event const &event);

		/**
		 * @brief listener on mouse begin collide with the input
		 *
		 * @param event mouse event
		 */
		void onMouseCollide(engine::event::Event const &event);

		/**
		 * @brief listener on mouse end collide with the input
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
	    std::string _value;
		std::function<void(std::string)> _on_submit;
	    std::size_t _max_chars;
	    engine::entity::Entity _input_entity;
	    engine::entity::Entity _value_entity;
	    engine::entity::Entity _title_entity;
		std::shared_ptr<engine::component::Position> _position;
		std::shared_ptr<sfml::component::Button> _input;
		std::shared_ptr<sfml::component::Text> _text;
	};

}

#endif /* !INPUTENTITY_HPP_ */
