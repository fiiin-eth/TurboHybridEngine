#include <memory>
#include <vector>

namespace TurboHybridEngine {

	struct Entity;
	struct Window;
	struct Resources;
	struct Input;
	struct Audio;
	struct GUI;

	/**
	* @struct Core
	* @brief The main engine struct responsible for initializing and running the engine.
	*/
	struct Core {

		/**
		* @brief Initializes the engine and returns a shared pointer to the Core instance.
		* @return A shared pointer to the initialized Core instance.
		*/
		static std::shared_ptr<Core> initialize();

		/**
		* @brief Starts the main game loop.
		*/
		void run();

		/**
		* @brief Adds a new entity to the engine.
		* @return A shared pointer to the newly added entity.
		*/
		std::shared_ptr<Entity> add_entity();

		/**
		* @brief Retrieves the engine's window.
		* @return A shared pointer to the Window instance.
		*/
		std::shared_ptr<Window> window() const;

		/**
		* @brief Retrieves the engine's resources manager.
		* @return A shared pointer to the Resources instance.
		*/
		std::shared_ptr<Resources> GetResources();

		/**
		* @brief Retrieves the input manager.
		* @return A shared pointer to the Input instance.
		*/
		std::shared_ptr<Input> get_input();

		/**
		* @brief Retrieves the GUI manager.
		* @return A shared pointer to the GUI instance.
		*/
		std::shared_ptr<GUI> gui();

		/**
		* @brief Finds and retrieves all components of a specified type from all entities.
		*
		* @tparam T The type of components to search for.
		* @param _out A vector to store the shared pointers to the found components.
		*/
		template <typename T>
		void Find(std::vector<std::shared_ptr<T> >& _out){
			for (size_t ei = 0; ei < m_entities.size(); ++ei){

				std::shared_ptr<Entity> e = m_entities.at(ei);
				for (size_t ci = 0; ci < e->m_components.size(); ++ci){

					std::shared_ptr<Component> c = e->m_components.at(ci);
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);
					if (t){

						_out.push_back(t);
					}
				}
			}
		}

	private:
		std::shared_ptr<Window> m_window;	///< The window instance of the engine.
		std::shared_ptr<Resources> m_resources;	///< The resources manager.
		std::shared_ptr<Input> m_input;	///< The input manager.
		std::shared_ptr<Audio> m_audio;	///< The audio manager.
		std::vector<std::shared_ptr<Entity>> m_entities;	///< List of all entities in the engine.
		std::weak_ptr<Core> m_self;	///< A weak pointer to the Core instance.
		std::shared_ptr<GUI> m_gui;	///< The GUI manager.

	};

}