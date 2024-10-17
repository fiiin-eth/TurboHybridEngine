#include "Transform.h"

namespace TurboHybridEngine {

	void Transform::on_initialize() {

		m_position = glm::vec3(0,0,0);
		m_rotation = glm::vec3(0,0,0);
		m_scale = glm::vec3(1,1,1);

	}

}