#include "Resource.h"

namespace TurboHybridEngine {

	std::string Resource::get_path() const
	{
		return m_path;
	}

	void Resource::load() {
		on_load();
	}

}