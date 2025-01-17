#include <memory>
#include <vector>

namespace TurboHybridEngine {

	struct Core;
	struct Component;

	/**
	* @struct Entity
	* @brief Represents an entity in the game engine that can have multiple components attached.
	*/
	struct Entity {

		/**
		* @brief Adds a new component of the specified type to the entity.
		*
		* @tparam T The type of the component to be added.
		* @return A shared pointer to the newly added component.
		*/
		template <typename T>
		std::shared_ptr<T> add_component() {
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;
			rtn->on_initialize();

			m_components.push_back(rtn);


			return rtn;
		}

		/**
		* @brief Retrieves a component of the specified type attached to the entity.
		*
		* @tparam T The type of the component to retrieve.
		* @return A shared pointer to the component if found, or nullptr if not found.
		*/
		template <typename T>
		std::shared_ptr<T> get_component(){
			for (size_t i = 0; i < m_components.size(); ++i)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(m_components[i]);
				if (rtn)
				{
					return rtn;
				}
			}

			return nullptr;
		}

		/**
		* @brief Retrieves the core engine instance associated with the entity.
		* @return A shared pointer to the Core instance.
		*/
		std::shared_ptr<Core> get_core() const;

	private:
		friend struct TurboHybridEngine::Core;
		friend struct Rigidbody;

		std::weak_ptr<Core> m_core; ///< Weak pointer to the core engine instance.
		std::weak_ptr<Entity> m_self; ///< Weak pointer to the entity itself.

		std::vector<std::shared_ptr<Component>> m_components; ///< List of components attached to the entity.

		/**
		* @brief Updates the entity each frame.
		* Called internally by the engine during the game loop.
		*/
		void tick();

		/**
		* @brief Renders the entity.
		* Called internally by the engine during the rendering phase.
		*/
		void render();

		/**
		* @brief Handles GUI events for the entity.
		* Called internally by the engine during the GUI event phase.
		*/
		void on_gui();
	};

}