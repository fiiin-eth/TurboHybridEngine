#include "Component.h"
#include "Core.h"
#include "Input.h"
#include "Entity.h"
#include "Transform.h"

namespace TurboHybridEngine {

	void Component::on_initialize() {}
	void Component::on_tick() {}
	void Component::on_render() {}
	void Component::on_gui() {}

	void Component::tick() {
		on_tick();
	}

	void Component::render() {
		on_render();
	}

	void Component::gui() {
		on_gui();
	}

	std::shared_ptr<Entity> Component::get_entity() {
		return m_entity.lock();
	}

	std::shared_ptr<Keyboard> Component::get_keyboard() {
		return get_entity()->get_core()->get_input()->GetKeyboard();

	}

	std::shared_ptr<Mouse> Component::get_mouse() {
		return get_entity()->get_core()->get_input()->GetMouse();
	}

	std::shared_ptr<Transform> Component::get_transform() {

		return get_entity()->get_component<Transform>();
	}

	glm::vec3 Component::get_position() {

		return get_transform()->getPosition();
	}

	std::shared_ptr<GUI> Component::get_gui() {
		return get_entity()->get_core()->gui();
	}

}