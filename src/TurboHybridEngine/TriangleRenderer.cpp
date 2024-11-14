#include "TriangleRenderer.h"
#include "Window.h"
#include "rend/Rend.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>


namespace TurboHybridEngine {

	//TriangleRenderer::TriangleRenderer() {}

	void TriangleRenderer::on_render() {
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);


		glm::vec3 catpos(0, 0, -15);
		float catAngle = 3.142f;
		glm::vec3 campos(0, 10, 20);
		glm::vec3 camrot(0, 0, 0);

		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.f);

		glm::mat4 View(1.0f);
		//View = glm::translate(View, campos);
		//View = glm::rotate(View, glm::radians(camrot.y), glm::vec3(0, 1, 0));
		//View = glm::inverse(View);

		glm::mat4 catModel(1.0f);
		catModel = glm::translate(catModel, catpos);
		//catModel = glm::rotate(catModel, glm::radians(catAngle), glm::vec3(0, 1, 0));

		m_shader.setMat4("u_Model", catModel);
		m_shader.setMat4("u_View", View);
		m_shader.setMat4("u_Projection", projection);
		m_shader.draw(m_model, m_texture);

		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
	}



}