#include "Resource.h"

namespace TurboHybridEngine {

	std::string Resource::getPath() const
	{
		return m_path;
	}

	void Resource::load() {
		onLoad();
	}



}