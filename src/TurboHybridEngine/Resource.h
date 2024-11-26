#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>

namespace TurboHybridEngine {

	struct Resources;
	struct Resource {

		std::string getPath() const;
		void setPath(const std::string& _path) { m_path = _path; }
		
		virtual void onLoad() = 0;

	private:
		friend struct TurboHybridEngine::Resources;

		std::string m_path;

		void load();
	};
}

#endif