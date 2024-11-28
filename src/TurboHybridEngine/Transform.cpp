#include "Transform.h"
#include <glm/ext/matrix_transform.hpp>

namespace TurboHybridEngine {

	void Transform::on_initialize() {

		m_position = glm::vec3(0,0,0);
		m_rotation = glm::vec3(0,0,0);
		m_scale = glm::vec3(1,1,1);

	}

	glm::mat4 Transform::GetModel()
	{
		glm::mat4 modelMatrix = glm::mat4(1.f);
		modelMatrix = glm::translate(modelMatrix, m_position);
		modelMatrix = glm::rotate(modelMatrix, glm::radians(m_rotation.x), glm::vec3(1, 0, 0));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(m_rotation.y), glm::vec3(0, 1, 0));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(m_rotation.z), glm::vec3(0, 0, 1));
		modelMatrix = glm::scale(modelMatrix, m_scale);

		return modelMatrix;
	}
}