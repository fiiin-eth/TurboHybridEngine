#include "Component.h"
#include <glm/glm.hpp>

namespace TurboHybridEngine {

	struct Transform : Component {

		void on_initialize();

		void setScale(glm::vec3 _scale) { m_scale = _scale; }
		glm::vec3 getScale() { return m_scale; }

		glm::mat4 GetModel();

		glm::vec3 m_position{0.0f};
		glm::vec3 m_rotation{0.0f};
		glm::vec3 m_scale{1.0f};

	};

}