#include <memory>
#include <vector>

namespace TurboHybridEngine {

	struct Entity;
	struct Window;
	struct Resources;
	class Input;

	struct Core {
		static std::shared_ptr<Core> initialize();

		void run();
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		std::shared_ptr<Resources> GetResources();
		std::shared_ptr<Input> get_input();

	private:
		std::shared_ptr<Window> m_window;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<Input> m_input;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;

	};

}