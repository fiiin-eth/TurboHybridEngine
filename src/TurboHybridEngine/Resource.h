#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>

namespace TurboHybridEngine {

	struct Resources;
	struct Resource {

		std::string getPath() const;
		
	private:
		friend struct TurboHybridEngine::Resources;

		virtual void onLoad() = 0;

		std::string m_path;

		void load();
	};
}

#endif