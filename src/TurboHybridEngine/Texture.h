#include "Resource.h"
#include "rend/Rend.h"
#include <memory>

namespace TurboHybridEngine {

	struct Texture : Resource {

		void onLoad();

	private:
		std::shared_ptr<Render::Texture> m_texture;

	};

	void Texture::onLoad() {
		m_texture = std::make_shared<Render::Texture>(getPath());

	}

}