#include "TriangleRenderer.h"
#include "Window.h"
#include "Entity.h"
#include "Transform.h"
#include "Texture.h"
#include "Model.h"
#include "Core.h"
#include "rend/Rend.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>


namespace TurboHybridEngine {

	TriangleRenderer::TriangleRenderer(){

	}

	void TriangleRenderer::setTexturePath(std::shared_ptr<Texture> _tex) {
		m_texture = _tex;
	}

	void TriangleRenderer::setModelPath(std::shared_ptr<Model> _model) {
		m_model = _model;
	}


	void TriangleRenderer::on_render() {
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);


		//glm::vec3 catpos(0, 0, -15);
		float catAngle = 3.142f;
		//glm::vec3 campos(0, 0, 0);
		//glm::vec3 camrot(0, 0, 0);

		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.f);

		glm::mat4 View(1.0f);

		View = glm::translate(View, glm::vec3(0.0f, 0.0f, 0.0f));
		View = glm::rotate(View, glm::radians(0.0f), glm::vec3(0, 1, 0));
		View = glm::rotate(View, glm::radians(0.0f), glm::vec3(1, 0, 0));
		View = glm::rotate(View, glm::radians(0.0f), glm::vec3(0, 0, 1));
		View = glm::inverse(View);

		Transform* transform = get_entity()->get_component<Transform>().get();

		//View = glm::translate(View, campos);
		//View = glm::rotate(View, glm::radians(camrot.y), glm::vec3(0, 1, 0));
		//View = glm::inverse(View);

		//glm::mat4 catModel(1.0f);
		//catModel = glm::translate(catModel, catpos);
		//catModel = glm::rotate(catModel, glm::radians(catAngle), glm::vec3(0, 1, 0));

		m_shader.setMat4("u_Model", transform->GetModel());
		m_shader.setMat4("u_View", View);
		m_shader.setMat4("u_Projection", projection);
		m_shader.draw(m_model->m_model.get(), m_texture->m_texture.get());

		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
	}

}