#pragma once

#include "Resource.h"
#include "rend/Rend.h"
#include <memory>

namespace TurboHybridEngine {

	struct Model : Resource {

		void on_load(){ m_model = std::make_shared<Render::Model>(get_path()); }
		std::shared_ptr<Render::Model> GetModel() { return m_model; }

	private:
		friend struct ModelRenderer;
		std::shared_ptr<Render::Model> m_model;

	};

}