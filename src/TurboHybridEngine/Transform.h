#include "Component.h"
#include <glm/glm.hpp>

namespace TurboHybridEngine {

	struct Transform : Component {

		void on_initialize();

		//scale
		void setScale(glm::vec3 _scale) { m_scale = _scale; }
		glm::vec3 getScale() { return m_scale; }

		//position
		void setPosition(glm::vec3 _position) { m_position = _position; }
		glm::vec3 getPosition() { return m_position; }

		//rotation
		void setRotation(glm::vec3 _rotation) { m_rotation = _rotation; }
		glm::vec3 getRotation() { return m_rotation; }

		glm::mat4 GetModel();

		glm::vec3 m_position{0.0f};
		glm::vec3 m_rotation{0.0f};
		glm::vec3 m_scale{1.0f};

	};

}