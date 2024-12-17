#ifndef TurboHybridEngine_COMPONENT_H
#define TurboHybridEngine_COMPONENT_H
#include <memory>
#include <glm/glm.hpp>
namespace TurboHybridEngine {


	struct Entity;
	class Keyboard;
	struct Mouse;
	struct Transform;

	struct Component {
	public:
		std::shared_ptr<Entity> get_entity();
		std::shared_ptr<Keyboard> get_keyboard();
		std::shared_ptr<Mouse> get_mouse();
		std::shared_ptr<Transform> get_transform();

		glm::vec3 get_position();

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