#ifndef TurboHybridEngine_COMPONENT_H
#define TurboHybridEngine_COMPONENT_H
#include <memory>

namespace TurboHybridEngine {


	struct Entity;
	class Keyboard;

	struct Component {
	public:
		std::shared_ptr<Entity> get_entity();
		std::shared_ptr<Keyboard> get_keyboard();

		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();

	private:
		friend struct Entity;

		std::weak_ptr<Entity> m_entity;
		void tick();
		void render();
	};

}

#endif