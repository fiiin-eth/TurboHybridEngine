#ifndef TRIANGLE_RENDERER_H
#define TRIANGLE_RENDERER_H

#include "Component.h"
//#include "Transform.h"
#include <rend/Rend.h>


namespace TurboHybridEngine {

	struct Model;
	struct Texture;

	struct TriangleRenderer : Component {
	public:
		TriangleRenderer();
		void on_render();

		void setTexturePath(std::shared_ptr<Texture> _tex);
		void setModelPath(std::shared_ptr<Model> _model);

	private:

		std::shared_ptr<Texture> m_texture;
		std::shared_ptr<Model> m_model;

		//Render::Model m_model;
		//Render::Texture m_texture;
		Render::Shader m_shader;
		//Render::Face m_face;



	};
}

#endif