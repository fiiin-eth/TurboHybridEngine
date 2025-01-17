#pragma once
#include <memory>
#include <glm/glm.hpp>
namespace TurboHybridEngine {


	struct Entity;
	struct Keyboard;
	struct Mouse;
	struct Transform;
	struct GUI;

	/**
	* @struct Component
	* @brief Base struct for all components that can be attached to an entity.
	*/
	struct Component {
	public:
		/**
		* @brief Retrieves the entity to which this component is attached.
		* @return A shared pointer to the Entity instance.
		*/
		std::shared_ptr<Entity> get_entity();

		/**
		* @brief Retrieves the keyboard input manager.
		* @return A shared pointer to the Keyboard instance.
		*/
		std::shared_ptr<Keyboard> get_keyboard();

		/**
		* @brief Retrieves the mouse input manager.
		* @return A shared pointer to the Mouse instance.
		*/
		std::shared_ptr<Mouse> get_mouse();

		/**
		* @brief Retrieves the transform component of the entity.
		* @return A shared pointer to the Transform instance.
		*/
		std::shared_ptr<Transform> get_transform();

		/**
		* @brief Retrieves the GUI manager associated with this component.
		* @return A shared pointer to the GUI instance.
		*/
		std::shared_ptr<GUI> get_gui();

		/**
		* @brief Retrieves the position of the entity.
		* @return A glm::vec3 representing the entity's position.
		*/
		glm::vec3 get_position();

		/**
		* @brief Called when the component is initialized.
		* Override this method for custom initialization logic.
		*/
		virtual void on_initialize();

		/**
		* @brief Called every frame to update the component.
		* Override this method for custom update logic.
		*/
		virtual void on_tick();

		/**
		* @brief Called during the rendering phase.
		* Override this method for custom rendering logic.
		*/
		virtual void on_render();

		/**
		* @brief Called during the GUI event phase.
		* Override this method for custom GUI handling logic.
		*/
		virtual void on_gui();

		virtual void on_collision();

	private:
		friend struct Entity;

		std::weak_ptr<Entity> m_entity; ///< Weak pointer to the entity this component is attached to.

		/**
		* @brief Internal tick method called by the engine.
		*/
		void tick();

		/**
		* @brief Internal render method called by the engine.
		*/
		void render();

		/**
		* @brief Internal GUI method called by the engine.
		*/
		void gui();

		void collision();
	};

}
