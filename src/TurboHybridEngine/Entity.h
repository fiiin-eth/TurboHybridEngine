#include <memory>
#include <vector>

namespace TurboHybridEngine {

	struct Core;
	struct Component;

	struct Entity {

		template <typename T>
		std::shared_ptr<T> add_component() {
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;
			rtn->on_initialize();

			m_components.push_back(rtn);


			return rtn;
		}

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
		std::shared_ptr<Core> get_core() const;

		//~Entity();
	private:
		friend struct TurboHybridEngine::Core;

		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;

		std::vector<std::shared_ptr<Component> > m_components;


		void tick();
		void render();
		void on_gui();
	};

}