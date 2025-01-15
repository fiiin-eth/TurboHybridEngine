#pragma once

#include "Resource.h"
#include "rend/Rend.h"
#include <memory>

namespace TurboHybridEngine {

	struct Texture : Resource {

		void on_load() { m_texture = std::make_shared<Render::Texture>(get_path()); }
		std::shared_ptr<Render::Texture> GetTexture() { return m_texture; }

	private:
		friend struct ModelRenderer;
		friend struct GUI;
		std::shared_ptr<Render::Texture> m_texture;

	};

}