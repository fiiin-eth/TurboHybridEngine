#ifndef MODEL_RENDERER_H
#define MODEL_RENDERER_H

#include "Component.h"
#include <rend/Rend.h>


namespace TurboHybridEngine {

	struct Model;
	struct Texture;

	struct ModelRenderer : Component {
	public:
		ModelRenderer();
		void on_render();

		void setTexturePath(std::shared_ptr<Texture> _tex);
		void setModelPath(std::shared_ptr<Model> _model);

	private:

		std::shared_ptr<Texture> m_texture;
		std::shared_ptr<Model> m_model;

		Render::Shader m_shader;
	};
}

#endif