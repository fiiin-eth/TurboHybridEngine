#pragma once

#include "Resource.h"
#include "rend/Rend.h"
#include <memory>

namespace TurboHybridEngine {

	struct Texture : Resource {

		void onLoad() { m_texture = std::make_shared<Render::Texture>(getPath()); }
		std::shared_ptr<Render::Texture> GetTexture() { return m_texture; }

	private:
		friend struct TriangleRenderer;
		friend struct GUI;
		std::shared_ptr<Render::Texture> m_texture;

	};

}