#include "Entity.h"
#include "Component.h"

namespace TurboHybridEngine {

	void Entity::tick() {
		for (size_t ci = 0; ci < m_components.size(); ++ci) {
			m_components.at(ci)->tick();
		}
	}

	void Entity::render() {
		for (size_t ci = 0; ci < m_components.size(); ++ci) {
			m_components.at(ci)->render();
		}
	}

	void Entity::on_gui() {
		for (size_t ci = 0; ci < m_components.size(); ++ci) {
			m_components.at(ci)->gui();
		}
	}

	std::shared_ptr<Core> Entity::get_core() const {
		return m_core.lock();

	}
}