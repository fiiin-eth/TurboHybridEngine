#include "GUI.h"
#include "Texture.h"
#include "Core.h"
#include "Input.h"
#include "Mouse.h"
#include <glm/ext.hpp>

namespace TurboHybridEngine {

	GUI::GUI(std::shared_ptr<Core> _core) {
		m_core = _core;
		
		Render::Face face;
		face.a.position = glm::vec3(1.0f, 0.0f, 0.0f);
		face.b.position = glm::vec3(0.0f, 1.0f, 0.0f);
		face.c.position = glm::vec3(0.0f, 0.0f, 0.0f);
		face.a.texcoord = glm::vec2(1.0f, 0.0f);
		face.b.texcoord = glm::vec2(0.0f, 1.0f);
		face.c.texcoord = glm::vec2(0.0f, 0.0f);
		m_mesh->add(face);

		Render::Face face2;
		face2.a.position = glm::vec3(1.0f, 0.0f, 0.0f);
		face2.b.position = glm::vec3(1.0f, 1.0f, 0.0f);
		face2.c.position = glm::vec3(0.0f, 1.0f, 0.0f);
		face2.a.texcoord = glm::vec2(1.0f, 0.0f);
		face2.b.texcoord = glm::vec2(1.0f, 1.0f);
		face2.c.texcoord = glm::vec2(0.0f, 1.0f);
		m_mesh->add(face2);
	}

	int GUI::Button(glm::vec2 _position, glm::vec2 _size, std::shared_ptr<Texture> _texture) {

		glm::mat4 model(1.0f);
		model = glm::translate(model, glm::vec3(_position.x, _position.y, 0));
		model = glm::scale(model, glm::vec3(_size.x, _size.y, 1.0f));
		m_shader->setMat4("u_Model", model);

		int width = 800;
		int height = 600;

		glm::mat4 ui_projection = glm::ortho(0.0f, (float)width, 0.0f, (float)height, 0.0f, 1.0f);
		m_shader->setMat4("u_Projection", ui_projection);

		m_shader->setMat4("u_View", glm::mat4(1.0f));

		m_shader->draw(m_mesh.get(), _texture->m_texture.get());

		int mouseX = m_core.lock()->get_input()->GetMouse()->get_xPosition();
		int mouseY = m_core.lock()->get_input()->GetMouse()->get_yPosition();

		glm::ivec2 mousePos = glm::ivec2(mouseX, mouseY);

		mousePos.y = height - mousePos.y;

		if (mousePos.x > _position.x && mousePos.x < _position.x + _size.x) {
			if (mousePos.y > _position.y && mousePos.y < _position.y + _size.y) {
				if (m_core.lock()->get_input()->GetMouse()->IsMouseDown(SDL_BUTTON_LEFT)) {
					return 1;
				}
			}
		}
		else {
			return 2;
		}

		return 0;


	}
}