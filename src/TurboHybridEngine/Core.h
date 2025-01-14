#include <memory>
#include <vector>

namespace TurboHybridEngine {

	struct Entity;
	struct Window;
	struct Resources;
	class Input;
	struct Audio;
	struct GUI;

	struct Core {
		static std::shared_ptr<Core> initialize();

		void run();
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		std::shared_ptr<Resources> GetResources();
		std::shared_ptr<Input> get_input();
		std::shared_ptr<GUI> gui();

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
		std::shared_ptr<Window> m_window;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<Input> m_input;
		std::shared_ptr<Audio> m_audio;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;
		std::shared_ptr<GUI> m_gui;

	};

}