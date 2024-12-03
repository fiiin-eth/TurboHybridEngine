#pragma once

#include "Resource.h"
#include "rend/Rend.h"
#include <memory>

namespace TurboHybridEngine {

	struct Model : Resource {

		void onLoad(){ m_model = std::make_shared<Render::Model>(getPath()); }
		std::shared_ptr<Render::Model> GetModel() { return m_model; }

	private:
		friend struct TriangleRenderer;
		std::shared_ptr<Render::Model> m_model;

	};

}