#include "Component.h"
#include <rend/Rend.h>


namespace TurboHybridEngine {


	struct TriangleRenderer : Component {

		TriangleRenderer();

	private:
		Render::Model m_model;
		Render::Mesh m_mesh;
		Render::Texture m_texture;
		Render::Shader m_shader;
		Render::Face m_face;

		void on_render();

	};


}