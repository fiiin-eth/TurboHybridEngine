#pragma once


#include "rend/Mesh.h"
#include "rend/ShaderProgram.h"

#include <memory>

namespace TurboHybridEngine {

	struct Core;
	struct Texture;

	struct GUI {
	public:
		GUI(std::shared_ptr<Core> _core);
		~GUI() {}

		int Button(glm::vec2 _position, glm::vec2 _size, std::shared_ptr<Texture> _texture);
		//void Image(glm::vec2 _position, glm::vec2 _size, std::shared_ptr<Texture> _texture);
		void test() {}

	private:
		std::shared_ptr<Render::Shader> m_shader = std::make_shared<Render::Shader>(true);
		std::shared_ptr<Render::Mesh> m_mesh = std::make_shared<Render::Mesh>();

		std::weak_ptr<Core> m_core;

	};


}