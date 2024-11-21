#pragma once

#include "Resource.h"
#include "rend/Rend.h"
#include <memory>

namespace TurboHybridEngine {

	struct Model : Resource {

		void onLoad();
		std::shared_ptr<Render::Model> GetModel();

	private:
		std::shared_ptr<Render::Model> m_model;

	};

	void Model::onLoad() {
		m_model = std::make_shared<Render::Model>(getPath());

	}

	std::shared_ptr<Render::Model> Model::GetModel() {
		return m_model;
	}

}